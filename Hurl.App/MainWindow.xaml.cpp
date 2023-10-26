#include "pch.h"
#include "MainWindow.xaml.h"
#include "winrt/Microsoft.UI.Interop.h"
#include <microsoft.ui.xaml.window.h>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Hurl_App::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        ExtendsContentIntoTitleBar(true);

        Microsoft::UI::Windowing::AppWindow x = GetAppWindowFromCurrent();
        x.Title(L"Hurlxxxxxxxxxxxxxxxx");
        x.Resize(winrt::Windows::Graphics::SizeInt32{ 1800, 600 });
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

    winrt::AppWindow MainWindow::GetAppWindowFromCurrent() {
        winrt::Hurl_App::MainWindow thisWindow = *this;
        winrt::com_ptr<IWindowNative> windowNative = thisWindow.as<IWindowNative>();

        //Get the HWND for the XAML Window
        HWND hWnd;
        windowNative->get_WindowHandle(&hWnd);

        // Get the WindowId for our window
        winrt::WindowId windowId;
        windowId = GetWindowIdFromWindow(hWnd);
        
        Microsoft::UI::Windowing::AppWindow appWindow = Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId);

        return appWindow;
    }
}
