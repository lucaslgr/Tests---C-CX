#pragma once
#include "Contador.h"; //Agrega��o

using Windows::UI::Popups::MessageDialog;
using namespace Windows::UI::Xaml::Controls;

namespace testeStaticClass {
	ref class Parametro
	{
		public:
			virtual ~Parametro();
			static void change_parametres();	//TODO 1 - Primeiro teste, m�todo est�tico
			property static int numPara;		//TODO 2 - Segundo teste, membro primitivo est�tico
			property static Contador ^c1;		//TODO 3 - Terceiro teste, objeto membro est�tico
			property static Button ^ btn_static;		//TODO 4 - Quarto teste, objeto j� definido no XAML como membro est�tico
		internal:
			Parametro();
			static void AtivationFactory();
	};
}

testeStaticClass::Parametro::Parametro()
{
}

inline void testeStaticClass::Parametro::AtivationFactory()
{
	Parametro::btn_static = ref new Button();
}


testeStaticClass::Parametro::~Parametro()
{
}

inline void testeStaticClass::Parametro::change_parametres()
{
	MessageDialog ^msg = ref new MessageDialog("Teste 1 de m�todo"); //Teste 1
	msg->ShowAsync();
}
