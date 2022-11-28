#include "winapi/button_browse.h"

#include <Windows.h>

namespace winapi
{
bool button_browse::on_push(std::wstring &directory)
{
    WCHAR path[MAX_PATH];
    OPENFILENAME open_file_name;
    const LPCWSTR filters = L"Text files *.txt\0*.txt\0"
                            L"JSON files *.json\0*.json\0";
    const auto flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    ZeroMemory(&open_file_name, sizeof(OPENFILENAME));
    std::memset(path, 0, sizeof(path));
    open_file_name.lStructSize = sizeof(OPENFILENAME);
    open_file_name.hInstance = (HINSTANCE)GetStockObject(NULL);
    open_file_name.hwndOwner = NULL;
    open_file_name.lpstrFile = path;
    open_file_name.nMaxFile = MAX_PATH;
    open_file_name.lpstrFilter = filters;
    open_file_name.nFilterIndex = 1;
    open_file_name.lpstrFileTitle = NULL;
    open_file_name.nMaxFileTitle = 0;
    open_file_name.lpstrInitialDir = NULL;
    open_file_name.Flags = flags;

    if (GetOpenFileName(&open_file_name))
    {
        directory = path;
        return 1;
    }
    return 0;
}
}