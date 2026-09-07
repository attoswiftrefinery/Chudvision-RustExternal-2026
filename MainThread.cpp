DWORD WINAPI MainThread(LPVOID hMod) {
    while (!GetModuleHandleA("GameAssembly.dll")) Sleep(50);

    while (!hooked) {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            kiero::bind(8, (void**)&oPresent, present_hk);
            break;
        }
        Sleep(50);
    }
    while (!g_unloaded) Sleep(500);
    FreeLibraryAndExitThread((HMODULE)hMod, 0);
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hMod);
        init_gfxreflex_proxy();
        CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
    }
    return TRUE;
}
