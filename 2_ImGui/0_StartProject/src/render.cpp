// render.cpp
#include "render.hpp"

WindowDataContainer::WindowDataContainer(){
//main.cpp -> jetzt render.cpp
    // Fensterliste erstellen ### VECTOREN ###
    windows.emplace_back("Demo-Fenster 1",
                         ImVec2(50, 200),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 2",
                         ImVec2(50, 300),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 3",
                         ImVec2(50, 400),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 4",
                         ImVec2(50, 500),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 5",
                         ImVec2(50, 600),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 6",
                         ImVec2(300, 200),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 7",
                         ImVec2(300, 300),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 8",
                         ImVec2(300, 400),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 9",
                         ImVec2(300, 500),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    windows.emplace_back("Demo-Fenster 10",
                         ImVec2(300, 600),
                         ImVec2(200, 75),
                         ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    //Zum erstellen von dropdown fenstern z.B. A anklicken und alle Woerter die mit A beginnen aufzeigen

    DropDownWindows.emplace_back("1 Drop-Fenster",        // title
                                 "A",                     // AtoZ
                                 "Words starting with A", // words
                                 ImVec2(50, 65),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("2 Drop-Fenster",        // title
                                 "B",                     // AtoZ
                                 "Words starting with B", // words
                                 ImVec2(50, 105),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("3 Drop-Fenster",        // title
                                 "B",                     // AtoZ
                                 "Words starting with B", // words
                                 ImVec2(50, 145),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("4 Drop-Fenster",        // title
                                 "B",                     // AtoZ
                                 "Words starting with B", // words
                                 ImVec2(50, 185),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

}

void RenderMenuWindow(MenuButtons &objM)
{
    // RenderMenuWindow wird nur aufgerufen, wenn das Spiel nicht gestartet ist
    if (!objM.gameStarted)
    {
        ImGui::SetNextWindowSize(ImVec2(450, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Menü");
        if (ImGui::Button("Start", ImVec2(200, 50)))
        {
            //Start-Logik
            objM.gameStarted = true;
        }
        if (ImGui::Button("Settings", ImVec2(200, 50)))
        {
            // Einstellungen-Logik
            objM.gameSettings = true;
        }
        if (ImGui::Button("Vocables", ImVec2(200, 50)))
        {
            // Vokabeln-Logik
            objM.gameVocables = true;
        }
        if (ImGui::Button("Exit", ImVec2(200, 50)))
        {
            // Exit-Logik
            objM.gameExit = true;
        }
        ImGui::End();
    }
}
//render.cpp
void RenderGameWindow(WindowDataContainer &objC, MenuButtons &objM, bool &backMenu)
{
    if (objM.gameStarted)
    {
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("SpielFenster");
        ImGui::SetCursorPos(ImVec2(0, 22));
        if (ImGui::Button("Back", ImVec2(150, 35)))
        {
            backMenu = true;
            objM.gameStarted = false;
        };

        for (const auto &winProps : objC.windows)
        {
            ImGui::SetCursorPos(winProps.position);
            if (ImGui::Button(winProps.title.c_str(), winProps.size))
            {
                // Button-Logik
                //TODO Die da diese logik muss über eine methode in der struktur implementiert werden können siehe header datei!
            }
        }
        ImGui::End();
    }
}
//render.cpp
void RenderSettingWindow(SettingButtons &objS, MenuButtons &objM, bool &backMenu)
{
    if (objM.gameSettings)
    {
        ImGui::SetNextWindowSize(ImVec2(450, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Einstellungen");
        if (ImGui::Button("Audio", ImVec2(200, 50)))
        {
            //Audio-Logik
        }
        if (ImGui::Button("Video", ImVec2(200, 50)))
        {
            // Video-Logik
        }
        if (ImGui::Button("Gameplay", ImVec2(200, 50)))
        {
            // Gameplay-Logik
        }
        if (ImGui::Button("Back", ImVec2(200, 50)))
        {
            // Gameplay-Logik
            backMenu = true;
            objM.gameSettings = false;
        }

        ImGui::End();
    }
}
//render.cpp
static int item_current_idx = 0; // Index des aktuell ausgewählten Items
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM, bool &backMenu)
{
    if (objM.gameVocables)
    {
        // In Ihrer Render-Schleife oder Funktion
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Vokabeln");
        ImGui::SetCursorPos(ImVec2(0, 22));
        if (ImGui::Button("Back", ImVec2(150, 35)))
        {
            backMenu = true;
            objM.gameVocables = false;
        };
        // Wenn Sie mehrere Combo-Boxen haben möchten, sollten Sie hier eine Schleife verwenden
        // Andernfalls entfernen Sie die Schleife, um nur eine Combo Box zu erstellen
        for (const auto &winProps : objC.DropDownWindows)
        {
                ImGui::SetCursorPos(winProps.position);
                // Setzen Sie die Breite des nächsten Widgets (der Combo-Box)
                ImGui::SetNextItemWidth(winProps.size.x); // Setzen Sie hier die gewünschte Breite

            if (ImGui::BeginCombo(winProps.title.c_str(), objC.DropDownWindows[item_current_idx].title.c_str())) // Verwenden Sie das text-Feld von VocableButtons
            {
                for (int n = 0; n < objC.DropDownWindows.size(); n++)
                {
                    bool is_selected = (item_current_idx == n);
                    if (ImGui::Selectable(objC.DropDownWindows[n].title.c_str(), is_selected))
                        item_current_idx = n;

                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }
        }

        ImGui::End();
    }
}
