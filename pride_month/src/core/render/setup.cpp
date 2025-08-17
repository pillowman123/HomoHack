#include "setup.h"

extern  LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

Present oPresent;

HWND window{};
WNDPROC oWndProc{};

ID3D11Device* pDevice{};
ID3D11DeviceContext* pContext{};
ID3D11RenderTargetView* targetView{};


LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	if (render::gui_base::isOpened)
		ClipCursor(NULL);

	return render::gui_base::isOpened ? true : CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


bool init{ false };
HRESULT WINAPI hkPresent(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags) {

	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);

			DXGI_SWAP_CHAIN_DESC desc{};
			pSwapChain->GetDesc(&desc);

			window = desc.OutputWindow;

			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &targetView);
			pBackBuffer->Release();

			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

			render::gui_base::initImGui(window, pDevice, pContext);

			init = true;
		}

		else
			return oPresent(pSwapChain, syncInterval, flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	static bool oneTimeSetup{ false };
	if (!oneTimeSetup) {
		oneTimeSetup = true;
		auto thread = SDK::IL2CPP::Utils::AttachThread();
	}

	render::gui_base::keyManager();
	render::gui::draw();

	if (globals::toggles::visuals::activateEsp) {
		auto networkedPlayerList = SDK::RR::Networking::RRPlayerNumbering::SortedPlayers();

		if (networkedPlayerList && networkedPlayerList->GetLength() >= 1) {
			for (int i = 0; i < networkedPlayerList->GetLength(); ++i) {
				auto objectCastedNp = networkedPlayerList->CastedPointer<SDK::IL2CPP::Il2CppObject*>()[i];

				if (objectCastedNp) {
					Pointers::Networking::NetworkedPlayer.Setup(objectCastedNp); //setup il2cpp methods for each valid target
					auto networkedPlayer = networkedPlayerList->GetPointer()[i];
					
					if (networkedPlayer) {
						auto actualPlayer = SDK::RR::Game::Player::GetFromActorNumber(networkedPlayer->get_ActorNumber());
						
						if (networkedPlayer) {
							cheats::esp::run(actualPlayer);
						}
					}
				}
			}
		}
	}


	ImGui::Render();

	pContext->OMSetRenderTargets(1, &targetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, syncInterval, flags);
}


DWORD WINAPI render::setup::createHook() {
	bool initHook{ false };
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			initHook = true;
		}
	} while (!initHook);
	return TRUE;
}