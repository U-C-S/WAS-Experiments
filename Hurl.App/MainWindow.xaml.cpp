// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#include "winrt/Microsoft.UI.Interop.h"
#include <microsoft.ui.xaml.window.h>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Hurl_App::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        ExtendsContentIntoTitleBar(true);

        //auto windowNative{ this->m_inner.as<::IWindowNative>() };
        //HWND hWnd{ 0 };
        //windowNative->get_WindowHandle(&hWnd);

        //Windowing::AppWindow x = GetAppWindowFromCurrent();
        //x.Title(L"Hurlx");
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

    //Windowing::AppWindow MainWindow::GetAppWindowFromCurrent() {
    //    winrt::Hurl_App::MainWindow thisWindow = *this;
    //    winrt::com_ptr<IWindowNative> windowNative = thisWindow.as<IWindowNative>();

    //    //Get the HWND for the XAML Window
    //    HWND hWnd;
    //    windowNative->get_WindowHandle(&hWnd);

    //    // Get the WindowId for our window
    //    WindowId windowId;
    //    windowId = GetWindowIdFromWindow(hWnd);
    //    
    //    Windowing::AppWindow appWindow = Windowing::AppWindow::GetFromWindowId(windowId);

    //    return appWindow;
    //}
}
