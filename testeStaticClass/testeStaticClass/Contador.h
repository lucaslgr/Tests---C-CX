#pragma once

namespace testeStaticClass {
	ref class Contador
	{
	public:
		
		property int static count; 
		virtual ~Contador();
		/*static void setORincrementCout();
		static void setORincrementCout(int value);*/
	internal:
		Contador();


		//TODO 4.3 - Quarto teste, solu��o: utilizar uma f�brica de ativa��o
		static void static_Construtor(); //Fabrica de ativa��o dos atributos est�ticos da classe
	};
	//TODO 4.0 - Quarto teste, inicializando membro est�tico com valor
	//int testeStaticClass::Contador::count = 1; 

	//TODO 4.1 - Quarto teste, inicializando membro est�tico com valor
	//Contador::setORincrementCout();
}
//TODO 4.2 - Quarto teste, inicializando membro est�tico com valor
//void testeStaticClass::Contador::setORincrementCout();

testeStaticClass::Contador::Contador()
{
}

inline void testeStaticClass::Contador::static_Construtor()
{
	Contador::count = 100;
}


testeStaticClass::Contador::~Contador()
{
}

//inline void testeStaticClass::Contador::setORincrementCout()
//{
//	Contador::count++;
//}
//
//inline void testeStaticClass::Contador::setORincrementCout(int value)
//{
//	Contador::count = value;
//}


