#pragma once
#include "Contador.h"; //Agrega��o

using Windows::UI::Popups::MessageDialog;

namespace testeStaticClass {
	ref class Parametro
	{
		public:
			virtual ~Parametro();
			static void change_parametres(); //TODO 1 - Primeiro teste, m�todo est�tico
			property static int numPara;	//TODO 2 - Segundo teste, membro primitivo est�tico
			property static Contador ^c1; //TODO 3 - Terceiro teste, objeto membro est�tico
		internal:
			Parametro();
}
	};

testeStaticClass::Parametro::Parametro()
{
}


testeStaticClass::Parametro::~Parametro()
{
}

inline void testeStaticClass::Parametro::change_parametres()
{
	MessageDialog ^msg = ref new MessageDialog("Teste 1 de m�todo"); //Teste 1
	msg->ShowAsync();
}
