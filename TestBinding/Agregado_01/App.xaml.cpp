﻿//
// App.xaml.cpp
// Implementação da classe App.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Agregado_01;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

/// <summary>
/// Inicializa o objeto singleton do aplicativo.  Esta é a primeira linha de código criado
/// executado e, como tal, é o equivalente lógico de main() ou WinMain().
/// </summary>
App::App()
{
    InitializeComponent();
    Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Invocado quando o aplicativo é iniciado normalmente pelo usuário final. Outros pontos de entrada
/// serão usados, por exemplo, quando o aplicativo for iniciado para abrir um arquivo específico.
/// </summary>
/// <param name="e">Detalhes sobre a solicitação e o processo de inicialização.</param>
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e)
{
    auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

    // Não repita a inicialização do aplicativo quando a Janela já tiver conteúdo,
    // apenas verifique se a janela está ativa
    if (rootFrame == nullptr)
    {
        // Criar um Quadro para agir como o contexto de navegação e associá-lo a
        // uma chave SuspensionManager
        rootFrame = ref new Frame();

        rootFrame->NavigationFailed += ref new Windows::UI::Xaml::Navigation::NavigationFailedEventHandler(this, &App::OnNavigationFailed);

        if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
        {
            // TODO: Restaurar o estado de sessão salvo somente quando apropriado, agendando as
            // etapas finais de inicialização depois que a restauração estiver concluída

        }

        if (e->PrelaunchActivated == false)
        {
            if (rootFrame->Content == nullptr)
            {
                // Quando a pilha de navegação não for restaurada, navegar para a primeira página,
                // configurando a nova página passando as informações necessárias como um parâmetro
                // parâmetro
                rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
            }
            // Coloque o quadro na Janela atual
            Window::Current->Content = rootFrame;
            // Verifique se a janela atual está ativa
            Window::Current->Activate();
        }
    }
    else
    {
        if (e->PrelaunchActivated == false)
        {
            if (rootFrame->Content == nullptr)
            {
                // Quando a pilha de navegação não for restaurada, navegar para a primeira página,
                // configurando a nova página passando as informações necessárias como um parâmetro
                // parâmetro
                rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
            }
            // Verifique se a janela atual está ativa
            Window::Current->Activate();
        }
    }
}

/// <summary>
/// Invocado quando a execução do aplicativo está sendo suspensa. O estado do aplicativo é salvo
/// sem saber se o aplicativo será encerrado ou retomado com o conteúdo
/// da memória ainda intacto.
/// </summary>
/// <param name="sender">A fonte da solicitação de suspensão.</param>
/// <param name="e">Detalhes sobre a solicitação de suspensão.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
    (void) sender;  // Parâmetro não usado
    (void) e;   // Parâmetro não usado

    //TODO: Salvar o estado do aplicativo e parar qualquer atividade em segundo plano
}

/// <summary>
/// Chamado quando ocorre uma falha na Navegação para uma determinada página
/// </summary>
/// <param name="sender">O Quadro com navegação com falha</param>
/// <param name="e">Detalhes sobre a falha na navegação</param>
void App::OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e)
{
    throw ref new FailureException("Failed to load Page " + e->SourcePageType.Name);
}