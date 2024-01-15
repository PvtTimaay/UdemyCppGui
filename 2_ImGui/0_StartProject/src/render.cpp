// render.cpp
#include "render.hpp"
#include <algorithm>
#include <sstream>

WindowDataContainer::WindowDataContainer() : item_current_idx(0){
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

    DropDownWindows.emplace_back("A",        // title
                                 "AtoZ_A",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 65),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("B",        // title
                                 "AtoZ_B",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 105),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("C",        // title
                                 "AtoZ_C",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 145),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("D",        // title
                                 "AtoZ_D",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 185),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("E",        // title
                                 "AtoZ_E",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 225),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("F",        // title
                                 "AtoZ_F",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 265),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("G",        // title
                                 "AtoZ_G",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 305),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("H",        // title
                                 "AtoZ_H",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 345),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("I",        // title
                                 "AtoZ_I",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 385),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("J",        // title
                                 "AtoZ_J",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 425),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("K",        // title
                                 "AtoZ_K",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 465),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("L",        // title
                                 "AtoZ_L",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 505),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("M",        // title
                                 "AtoZ_M",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 545),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("N",        // title
                                 "AtoZ_N",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 65),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("O",        // title
                                 "AtoZ_O",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 105),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("P",        // title
                                 "AtoZ_P",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 145),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("Q",        // title
                                 "AtoZ_Q",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 185),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("R",        // title
                                 "AtoZ_R",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 225),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("S",        // title
                                 "AtoZ_S",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 265),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("T",        // title
                                 "AtoZ_T",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 305),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("U",        // title
                                 "AtoZ_U",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 345),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("V",        // title
                                 "AtoZ_V",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 385),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("W",        // title
                                 "AtoZ_W",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 425),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("X",        // title
                                 "AtoZ_X",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 465),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("Y",        // title
                                 "AtoZ_Y",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 505),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("Z",        // title
                                 "AtoZ_Z",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 545),         // position
                                 ImVec2(165, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    for (auto &winProps : DropDownWindows)      //TODO diese den vectoren beigefügten wörter, müssen jetzt noch richtig in der RenderVocableWindow eingebaut werden
    {
      // winProps.addWord("Apfel", "Apple");

           //saveWordsToFile(winProps.wordsVec, winProps.wordsVecTranslate, winProps.AtoZ);
           takeWordsFromFile(winProps.AtoZ, winProps.wordsVec, winProps.wordsVecTranslate, winProps.selectedStates);
            for (size_t i = 0; i < winProps.wordsVec.size(); i++)
            {
                std::cout << winProps.wordsVec[i] << " ";
            }

    }

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
void RenderGameWindow(WindowDataContainer &objC, MenuButtons &objM)
{
    if (objM.gameStarted)
    {
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("SpielFenster");
        ImGui::SetCursorPos(ImVec2(0, 22));
        if (ImGui::Button("Back", ImVec2(150, 35)))
        {
            objM.ZurueckMenue = true;
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
void RenderSettingWindow(MenuButtons &objM)
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
            // Back-Logik
            objM.ZurueckMenue = true;
            objM.gameSettings = false;
        }

        ImGui::End();
    }
}

//render.cpp
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM) {
    if (objM.gameVocables) {
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Vokabeln");
        ImGui::SetCursorPos(ImVec2(0, 22));
        if (ImGui::Button("Back", ImVec2(150, 35))) {
            objM.ZurueckMenue = true;
            objM.gameVocables = false;
        }

        // Iterieren Sie über jedes Dropdown-Fenster
        for (auto &winProps : objC.DropDownWindows) {
            ImGui::SetCursorPos(winProps.position);
            ImGui::SetNextItemWidth(winProps.size.x);


if (ImGui::BeginCombo(winProps.title.c_str(), winProps.words.c_str())) {
    int selectedCount = 0; // Zähler für ausgewählte Elemente in dieser Kategorie

    for (auto& item : objC.DropDownWindows) {
        for (size_t i = 0; i < item.wordsVec.size(); ++i) {
            if (item.AtoZ == winProps.AtoZ) {
                bool isSelected = (i < item.selectedStates.size()) ? item.selectedStates[i] : false;

                if (ImGui::Selectable(item.wordsVec[i].c_str(), &isSelected)) {
                    if (i < item.selectedStates.size()) {
                        item.selectedStates[i] = isSelected;
                    }
                }
                // Aktualisieren Sie den Zähler für ausgewählte Elemente
                if (isSelected) {
                    selectedCount++;
                }
            }
        }
    }

    ImGui::EndCombo();
    winProps.words = std::to_string(selectedCount) + " ausgewählt"; // Anzeige der Anzahl ausgewählter Elemente
}
        }

        ImGui::End();
    }
}

//hilfsfunktionen
void saveWordsToFile(const std::vector<std::string>& wordsVec, const std::vector<std::string>& wordsVecTranslate, const std::string& filePath) {
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Fehler beim Oeffnen der Datei: " << filePath << std::endl;
        return;
    }
    if (wordsVec.size() != wordsVecTranslate.size())
    {
        std::cerr << "Fehler, vectoren weisen nicht die gleiche groesse auf!" << std::endl;
        return;
    }

    for (int i = 0; i < wordsVec.size(); i++) {
        outFile << wordsVec[i] << "," << wordsVecTranslate[i] << std::endl;
    }

    outFile.close();
}

void takeWordsFromFile(const std::string& filePath, std::vector<std::string>& wordsVec, std::vector<std::string>& wordsVecTranslate, std::vector<bool>& selectedStates) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Fehler beim Oeffnen der Datei: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            std::istringstream lineStream(line);
            std::string word, translation;

            // Erstes Wort vor dem Komma
            std::getline(lineStream, word, ',');

            // Zweites Wort nach dem Komma
            std::getline(lineStream, translation);

            wordsVec.push_back(word);
            wordsVecTranslate.push_back(translation);
            selectedStates.push_back(false);
        }

    }

    inFile.close();

    if (wordsVec.size() != wordsVecTranslate.size()) {
    std::cerr << "Fehler, ungleichgrosse Vektoren: Bitte Woerter in .txt ueberpruefen" << std::endl;
    return;
    }

    for (size_t i = 0; i < wordsVec.size(); ++i) {
        if (wordsVec[i].empty() || wordsVecTranslate[i].empty()) {
        std::cerr << "Fehler, leere Eintraege gefunden: Bitte Woerter in .txt ueberpruefen" << std::endl;
        break; // Schleife abbrechen, da ein Fehler gefunden wurde
        }
    }

}

void saveWordsToFileFromMap(const std::unordered_map<std::string, std::string>& map, const std::string& fileName) {
    std::ofstream outFile1(fileName);

    if (!outFile1) {
        std::cerr << "Fehler beim Öffnen der Datei zum Schreiben." << std::endl;
        return;
    }

    for (const auto& pair : map) {
        outFile1 << pair.first << "," << pair.second << std::endl;
    }

    outFile1.close();
}

void TakeWordsFromFileToMap(const std::string& fileName, std::unordered_map<std::string, std::string>& map, std::vector<bool>& selectedStates) {
     std::ifstream inFile(fileName);
    std::string line;

    if (!inFile) {
        std::cerr << "Fehler beim Öffnen der Datei: " << fileName << std::endl;
        return;
    }

    while (std::getline(inFile, line)) {
        std::istringstream lineStream(line);
        std::string key, value;

        if (std::getline(lineStream, key, ',') && std::getline(lineStream, value)) {
            map[key] = value;
            selectedStates.push_back(false);
        }
    }

    inFile.close();
}
