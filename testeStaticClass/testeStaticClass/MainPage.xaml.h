﻿//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace testeStaticClass
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Teste1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Teste2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void AtivationClass_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Teste3_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Teste4_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
