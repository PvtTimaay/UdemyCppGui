// render.cpp
#include "render.hpp"
#include <algorithm>
#include <sstream>
#include <filesystem>
#include <random>
#include "json.hpp"

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

    //NOTE Zum erstellen von dropdown fenstern z.B. A anklicken und alle Woerter die mit A beginnen aufzeigen

    DropDownWindows.emplace_back("A",        // title
                                 "AtoZ_A.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 65),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("B",        // title
                                 "AtoZ_B.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 105),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("C",        // title
                                 "AtoZ_C.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 145),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("D",        // title
                                 "AtoZ_D.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 185),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("E",        // title
                                 "AtoZ_E.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 225),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("F",        // title
                                 "AtoZ_F.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 265),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("G",        // title
                                 "AtoZ_G.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 305),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("H",        // title
                                 "AtoZ_H.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 345),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("I",        // title
                                 "AtoZ_I.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 385),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("J",        // title
                                 "AtoZ_J.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 425),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("K",        // title
                                 "AtoZ_K.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 465),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("L",        // title
                                 "AtoZ_L.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 505),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("M",        // title
                                 "AtoZ_M.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(50, 545),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("N",        // title
                                 "AtoZ_N.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 65),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("O",        // title
                                 "AtoZ_O.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 105),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("P",        // title
                                 "AtoZ_P.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 145),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("Q",        // title
                                 "AtoZ_Q.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 185),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("R",        // title
                                 "AtoZ_R.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 225),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("S",        // title
                                 "AtoZ_S.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 265),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("T",        // title
                                 "AtoZ_T.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 305),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("U",        // title
                                 "AtoZ_U.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 345),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("V",        // title
                                 "AtoZ_V.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 385),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("W",        // title
                                 "AtoZ_W.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 425),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("X",        // title
                                 "AtoZ_X.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 465),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("Y",        // title
                                 "AtoZ_Y.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 505),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    DropDownWindows.emplace_back("Z",        // title
                                 "AtoZ_Z.txt",                     // AtoZ
                                 "Words starting with AtoZ", // words
                                 ImVec2(350, 545),         // position
                                 ImVec2(164, 25),         // size
                                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

for (auto &winProps : DropDownWindows)
    {
        /*winProps.addWord("Apfel", "Apple");
        winProps.addWord("Birne", "Pear");
        winProps.addWord("Citrone", "Lemon");
        winProps.addWord("Dattel", "Date");
        winProps.addWord("Erbse", "Pea");*/

           //saveWordsToFile(winProps.wordsVec, winProps.wordsVecTranslate, winProps.AtoZ);
           //takeWordsFromFile(winProps.AtoZ, winProps.wordsVec, winProps.wordsVecTranslate, winProps.selectedStates);

            for (size_t i = 0; i < winProps.wordsVec.size(); i++)
            {
                std::cout << winProps.wordsVec[i] << " ";
            }

            std::cout << '\n\n';


            parseFromJsonFuncWords(winProps.AtoZ, winProps.wordsVec, winProps.wordsVecTranslate);
            parseFromJsonFuncConfig(winProps.title, winProps.words, winProps.selectedStates);

            for (size_t i = 0; i < winProps.wordsVec.size(); i++)
            {
                std::cout << winProps.wordsVec[i] << " ";
            }

            std::cout << '\n\n';
    }
}

void RenderMenuWindow(WindowDataContainer &objC, MenuButtons &objM, GameString &objS)
{
    // RenderMenuWindow wird nur aufgerufen, wenn das Spiel nicht gestartet ist
    if (!objM.gameStarted)
    {
        ImGui::SetNextWindowSize(ImVec2(450, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Menü", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        if (ImGui::Button("Start", ImVec2(200, 50)))
        {
            //Start-Logik
            gameStringLoader(objC, objS);
            gameWindowPosLoader(objC, objS); //NOTE shuffle die window positions der letzten 5 Elemente
            loadToGameFunction(objC, objS); //NOTE Funktion die strings aus GameString Struktur ins Spiel läd
            objM.gameStarted = true;
        }
        if (ImGui::Button("Settings", ImVec2(200, 50)))
        {
            // Einstellungen-Logik
            objM.gameSettings = true;
        }
        if (ImGui::Button("Vocables", ImVec2(200, 50)))
        {
            //Vokabeln-Logik
            //takeWordsFromFileObject(objC); //TODO wenn man woerter manuell in die .txt eintraegt müssen diese richtig in die string vectoren und .json datei geupdatet werden
            parseToJsonFuncConfig(objC);
            parseToJsonFuncWords(objC);
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
void RenderGameWindow(WindowDataContainer &objC, MenuButtons &objM, GameString &objS)
{
    if (objM.gameStarted)
    {
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("SpielFenster", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SetCursorPos(ImVec2(0, 22));
        if (ImGui::Button("Back", ImVec2(150, 35)))
        {
            objM.ZurueckMenue = true;
            objM.gameStarted = false;
        };

        for (auto &winProps : objC.windows)
        {
            if (!winProps.selectedWindow2)
            {
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.5f, 0.5f, 0.5f, 0.5f)); //NOTE false
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.8f, 0.8f, 0.8f)); //NOTE true
            }
            ImGui::SetCursorPos(winProps.position);
            if (ImGui::Button(winProps.title.c_str(), winProps.size))
            {
                // Button-Logik
                winProps.selectedWindow2 = !winProps.selectedWindow2;
                buttonLogic(objC, objS);
            }
            ImGui::PopStyleColor();
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
        ImGui::Begin("Einstellungen", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
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
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM, GameString &objS) {
    if (objM.gameVocables)
    {
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Vokabeln", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SetCursorPos(ImVec2(0, 22));
        if (ImGui::Button("Back", ImVec2(150, 35)))
        {
            objM.ZurueckMenue = true;
            objM.gameVocables = false;
            loadToGameFunction(objC, objS); //TODO Funktion die strings aus GameString Struktur ins Spiel läd
        }

        ImGui::SetCursorPos(ImVec2(750, 350));
        if (ImGui::Button("Apply", ImVec2(350, 350)))
        {
            objM.gameVocablesApplyFunc = true;
            objM.ZurueckMenue = true;
            objM.gameVocables = false;
            gameStringLoader(objC, objS);     //NOTE String lade Funktion, ab hier werden die choosedWords.txt strings in die GameString geladen
            loadToGameFunction(objC, objS); //NOTE Funktion die strings aus GameString Struktur ins Spiel läd
            parseToJsonFuncConfig(objC);          //NOTE Alle ausgewaehlten/abgewaehlten elemente/widgets der selectable fenster in .json datei speichern
        }

        /*ImGui::SetCursorPos(ImVec2(750, 100)); //WARN #1 funktioniert nicht richtig da alle ImGui::BeginCombo aktualisiert werden müssen um selectedCount zu aktualisieren indem man sie alle einzeln anklickt
        if (ImGui::Button(objM.vocableSelectAll.c_str(), ImVec2(100, 50))) //TODO <<-- alle elemente von allen werden ausgewaehlt, button veraendert farbe
        {   //TODO sobald der benutzer auswaehlt, aendert button name zu "custom"
           // objM.vocableSelectAll = "custom"; //NOTE test
           for (auto &item : objC.DropDownWindows)
           {
                    for (int i = 0; i < item.wordsVec.size(); i++)
                    {
                        item.selectedStates[i] = true;  //TODO selectedCount wird nicht direkt mit aktualisiert, nur beim drücken der jeweiligen dropDownFenster
                    }
           }
        }*/ //WARN #1 oben

        // Iterieren Sie über jedes Dropdown-Fenster
        for (auto &winProps : objC.DropDownWindows)
        {
            ImGui::SetCursorPos(winProps.position);
            ImGui::SetNextItemWidth(winProps.size.x);

            if (ImGui::BeginCombo(winProps.title.c_str(), winProps.words.c_str()))
            {
                int selectedCount {}; //NOTE Zähler für ausgewählte Elemente in dieser Kategorie
                for (size_t i = 0; i < winProps.wordsVec.size(); ++i)
                {
                    if (winProps.AtoZ == winProps.AtoZ)
                    {
                        bool isSelected = (i < winProps.selectedStates.size()) ? winProps.selectedStates[i] : false;
                        if (ImGui::Selectable(winProps.wordsVec[i].c_str(), &isSelected)) //NOTE <--hier wird bei klick aufs selectable-widget der wert &isSelected auf true/false gesetzt
                        {
                            if (i < winProps.selectedStates.size())
                            {
                                winProps.selectedStates[i] = isSelected;
                            }
                        }
                        if (isSelected)
                        {
                            selectedCount++; //NOTE Dieser Zaehler wird auch in der json datei gespeichert
                        }
                    }
                }

                winProps.words = std::to_string(selectedCount) + " ausgewählt"; //NOTE Anzeige der Anzahl ausgewählter Elemente
                ImGui::EndCombo();
            }

            std::string buttonLabel = "<=Add" + winProps.title; //NOTE Generiert einen einzigartigen Label für jeden Button
            ImGui::SetCursorPos(ImVec2(winProps.position.x + 200, winProps.position.y));
            if (ImGui::Button(buttonLabel.c_str(), ImVec2(winProps.size.x - 100, winProps.size.y - 25)))
            {
                //NOTE Logik für den Button-Klick
                winProps.selectedVoc1 = true;
                objM.gameVocablesOpenAddWindow = true;
                //NOTE Zum Beispiel: Öffnen eines neuen Fensters, Ausführen einer Funktion, etc.
            }
        }
        ImGui::End();
    }
}

//hilfsfunktion
void saveWordsToFile(const std::vector<std::string>& wordsVec, const std::vector<std::string>& wordsVecTranslate, const std::string& filePath)
{

    std::filesystem::path thisPath = std::filesystem::current_path();
    thisPath /= "files";
    thisPath /= filePath;

        // Überprüfen, ob der Ordner existiert, wenn nicht, erstelle ihn
    if (!std::filesystem::exists(thisPath.parent_path()))
    {
        std::filesystem::create_directory(thisPath.parent_path());
    }

    std::ofstream outFile(thisPath, std::ios::app);
    if (!outFile) {
        std::cerr << "Fehler beim Oeffnen der Datei: " << filePath << '\t' << thisPath << std::endl;
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

//hilfsfunktion
void takeWordsFromFileObject(WindowDataContainer &objC) //NOTE REFACTORY TEST!
{
    std::filesystem::path thisPath = std::filesystem::current_path();
    thisPath /= "files";
    for (auto &item : objC.DropDownWindows)
    {
        std::filesystem::path tempPath = thisPath;
        tempPath /= item.AtoZ;

        std::ifstream inFile(tempPath);
        if (!inFile)
        {
            std::cerr << "Fehler beim Oeffnen der Datei: " << item.AtoZ << '\t' << tempPath << '\n';
            return;
        }

        std::string line;
        while (std::getline(inFile, line))
        {
            if (!line.empty())
            {
                std::istringstream lineStream(line);
                std::string word, translation;

                //NOTE Erstes Wort vor dem Komma
                std::getline(lineStream, word, ',');
                if (!std::any_of(item.wordsVec.begin(), item.wordsVec.end(), [&word](const std::string &w){ return w == word;}))
                {
                         //NOTE Zweites Wort nach dem Komma
                     std::getline(lineStream, translation);
                     if (!std::any_of(item.wordsVecTranslate.begin(), item.wordsVecTranslate.end(), [&translation](const std::string &t){ return t == translation;}))
                     {
                        item.wordsVec.push_back(word);
                        item.wordsVecTranslate.push_back(translation);
                        item.selectedStates.push_back(false);
                     }
                }
            }
        }
        inFile.close();

        if (item.wordsVec.size() != item.wordsVecTranslate.size())
        {
            std::cerr << "Fehler, ungleichgrosse Vektoren: Bitte Woerter in " << item.AtoZ << ".txt ueberpruefen" << std::endl;
            return;
        }
        else if (item.wordsVec.empty() || item.wordsVecTranslate.empty())
        {
            std::cerr << "Fehler, leere Eintraege gefunden: Bitte Woerter in " << item.AtoZ << ".txt ueberpruefen" << std::endl;
        }
    }
}
//hilfsfunktion
void takeWordsFromFile(const std::string& filePath, std::vector<std::string>& wordsVec, std::vector<std::string>& wordsVecTranslate, std::vector<bool>& selectedStates)
{
    std::filesystem::path thisPath = std::filesystem::current_path();
    thisPath /= "files";
    thisPath /= filePath;

    std::ifstream inFile(thisPath);
    if (!inFile)
    {
        std::cerr << "Fehler beim Oeffnen der Datei: " << filePath << '\t' << thisPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
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
        break; //NOTE Schleife abbrechen, da ein Fehler gefunden wurde
        }
    }
}

//hilfsfunktion
void parseToJsonFuncWords (WindowDataContainer &objC)
{
    std::filesystem::path thisPath = std::filesystem::current_path();
    thisPath /= "files";
    thisPath /= "words.json";

    if(!std::filesystem::exists(thisPath.parent_path()))
    {
        std::filesystem::create_directory(thisPath.parent_path());
    }

    if(!std::filesystem::exists(thisPath))
    {
        //Datei erstellen mit leerem Json Objekt
        std::ofstream outFile(thisPath);
        outFile << "{}";
        outFile.close();
    }
    else
    {
        nlohmann::json jArray = nlohmann::json::array();
        for(const auto item : objC.DropDownWindows)
        {
            nlohmann::json tempJson;
            tempJson [item.AtoZ + " wordsVec"] = item.wordsVec;
            tempJson [item.AtoZ + " wordsVecTranslate"] = item.wordsVecTranslate;
            jArray.push_back(tempJson);
        }
        nlohmann::json j;
        j = jArray;
        std::ofstream jsonWordsFile(thisPath);
        if(jsonWordsFile.is_open())
        {
            jsonWordsFile << j.dump(4);
            jsonWordsFile.close();
        }
    }
}

//hilfsfunktion
void parseFromJsonFuncWords (const std::string& filePath, std::vector<std::string>& wordsVec, std::vector<std::string>& wordsVecTranslate)
{
    std::filesystem::path thisPathWords = std::filesystem::current_path();
    thisPathWords /= "files";
    thisPathWords /= "words.json";
    std::string keyBeginning = filePath;

    if (!std::filesystem::exists(thisPathWords.parent_path()))
    {
        std::filesystem::create_directory(thisPathWords.parent_path());
    }

    if (!std::filesystem::exists(thisPathWords))
    {
        std::cout << "words.json not even exists!\n";
        return;
    }
    else
    {
        std::ifstream inFile(thisPathWords);
        nlohmann::json jsonData;
        inFile >> jsonData;
        inFile.close();

        for (const auto &entry : jsonData)
        {

            if (entry.contains(keyBeginning + " wordsVec") && entry.contains(keyBeginning + " wordsVecTranslate"))
            {
                //einlesen in die std::vectoren
                    wordsVec = entry[keyBeginning + " wordsVec"].get<std::vector<std::string>>();
                    wordsVecTranslate = entry[keyBeginning + " wordsVecTranslate"].get<std::vector<std::string>>();

                    std::cout << "words.json key successfull found in " << filePath << std::endl;
                    return;
            }
            else
            {
                    std::cerr << "Error, json keys not found, please check the words.json file\n\n";
            }
        }
    }
}

//render.cpp
//hilfsfunktion
void gameVocablesApplyFunction(WindowDataContainer& objC, MenuButtons& objM)
{
    if (objM.gameVocablesApplyFunc)
    {
        std::filesystem::path thisPath = std::filesystem::current_path();
        std::string filePath1 = "ChoosedWords.txt";
        thisPath /= "files";
        thisPath /= filePath1;

        std::ofstream outFileVecs(thisPath);
        if (!outFileVecs) {
            std::cerr << "Fehler beim Öffnen der Datei (ChoosedWords.txt)" << std::endl;
            return;
        }

        for (auto &item : objC.DropDownWindows) {
            for (size_t i = 0; i < item.wordsVec.size(); ++i) {
                if (i < item.selectedStates.size() && item.selectedStates[i]) {
                    outFileVecs << item.wordsVec[i] << "," << item.wordsVecTranslate[i] << std::endl;
                }
            }
        }
        objM.gameVocablesApplyFunc = false;
    }
}

//render.cpp
//hilfsfunktion
void gameVocablesAddFunction(WindowDataContainer &objC, MenuButtons & objM)
{
    if (objM.gameVocablesOpenAddWindow)
    {
        static char word1[128] = "";
        std::string windowTitle = "Texteingabe-Fenster";
        for (auto &item : objC.DropDownWindows) //hier wird das element im vector gesucht mit dem bool selected = true um den dazugehörigen title als FensterNamen angeben zu koennen
        {
            if (item.selectedVoc1 == true)
            {
                windowTitle = item.title;
                break;
            }

        }
        ImGui::SetNextWindowSize(ImVec2(450, 250));
        ImGui::Begin(windowTitle.c_str());
        ImGui::InputText("word,word", word1, IM_ARRAYSIZE(word1)); //TODO diesem Fenster noch ein Textfeld hinzufügen worin steht das word,word gewissenhaft eingegeben werden muss weil sonst im spiel ein leeres textfeld angezeigt wird oder programmabsturz

        ImGui::SetCursorPos(ImVec2(250, 175));
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
        if(ImGui::Button("delete selected words", ImVec2(160, 20)))
        {
            for (auto &winProps : objC.DropDownWindows)
            {
                for (size_t i = 0; i < winProps.wordsVec.size(); )
                {
                    if (winProps.selectedStates[i] && winProps.selectedVoc1 == true)
                    {
                        //NOTE Element löschen
                        winProps.wordsVec.erase(winProps.wordsVec.begin() + i);
                        winProps.wordsVecTranslate.erase(winProps.wordsVecTranslate.begin() + i);
                        winProps.selectedStates.erase(winProps.selectedStates.begin() + i);
                        //NOTE Kein i++ hier, da das nächste Element an die Stelle des gelöschten Elements rückt
                    }
                    else
                    {
                        //NOTE Nur erhöhen, wenn kein Element gelöscht wurde
                        ++i;
                    }
                }
                if (winProps.selectedVoc1 == true)
                {
                    std::filesystem::path thisPath = std::filesystem::current_path();
                    thisPath /= "files";
                    thisPath /= winProps.AtoZ;
                    std::ofstream outFile(thisPath);
                    if (!outFile)
                    {
                        std::cerr << "Fehler beim Oeffnen der Datei: " << winProps.AtoZ << std::endl;
                        return;
                    }
                    if (winProps.wordsVec.size() != winProps.wordsVecTranslate.size())
                    {
                        std::cerr << "Fehler, vectoren weisen nicht die gleiche groesse auf!" << std::endl;
                        return;
                    }
                    for (int i = 0; i < winProps.wordsVec.size(); i++)
                    {
                        outFile << winProps.wordsVec[i] << "," << winProps.wordsVecTranslate[i] << std::endl;
                    }

                    outFile.close();
                    winProps.selectedVoc1 = false;
                }
            }
            std::fill(std::begin(word1), std::end(word1), 0); //NOTE word1 wieder leeren
            objM.gameVocablesOpenAddWindow = false;
            parseToJsonFuncConfig(objC); //NOTE ""
            parseToJsonFuncWords(objC);
        }
        ImGui::PopStyleColor();

        ImGui::SetCursorPos(ImVec2(250, 50));
        if(ImGui::Button("back", ImVec2(100, 50)))
        {
            for (auto & item : objC.DropDownWindows)
            {
                if (item.selectedVoc1 == true)
                {
                    item.selectedVoc1 = false;
                }
            }
            std::fill(std::begin(word1), std::end(word1), 0); //NOTE word1 wieder leeren
            objM.gameVocablesOpenAddWindow = false;
        }

        ImGui::SetCursorPos(ImVec2(1, 50));
        if (ImGui::Button("Confirm", ImVec2(150, 150)))
        {
            for (auto &item : objC.DropDownWindows)
            {
                if (word1[0] == '\0')
                {
                    std::cout << "Fehler, Leeres Textfeld!" << std::endl;
                    //TODO diese Fehlermeldung dem Benutzer anzeigen
                    break;
                }
                else if (item.selectedVoc1 == true) //NOTE schreibt nur Woerter für das angeklickte Add-Fenster!
                {
                    std::string inputString = {word1}; //NOTE word1 wird am Komma gesplittet um beide vectoren befüllen zu können
                    std::istringstream stream(inputString);
                    std::string firstWord, secondWord;

                    std::getline(stream, firstWord, ',');
                    std::getline(stream, secondWord);
                    if (firstWord.empty() || secondWord.empty())
                    {
                        std::cout << "Fehler, bitte geben sie Gewissenhaft zwei Woerter getrennt durch ein Komma ein" << std::endl;
                        //TODO diese Fehlermeldung dem Benutzer anzeigen
                    }
                    else
                    {
                        item.addWord(firstWord, secondWord);

                        std::vector<std::string> tempVecString1 = {firstWord};
                        std::vector<std::string> tempVecString2 = {secondWord};
                        saveWordsToFile(tempVecString1, tempVecString2, item.AtoZ);
                    }
                }
                if (item.selectedVoc1 == true)
                {
                    item.selectedVoc1 = false;
                }
            }
            std::fill(std::begin(word1), std::end(word1), 0); // word1 wieder leeren
            objM.gameVocablesOpenAddWindow = false;
            parseToJsonFuncConfig(objC); //NOTE ""
            parseToJsonFuncWords(objC);
        }
        ImGui::End();
    }
}

//hilfsfunktion
void gameStringLoader(WindowDataContainer &objC, GameString &objS)
{
    std::vector<std::string> tempVec {};
    std::vector<std::string> tempVecTrans {};
    std::filesystem::path current_path_obj = std::filesystem::current_path();
    current_path_obj /= "files";
    current_path_obj /= "ChoosedWords.txt";

        std::ifstream inFile(current_path_obj);
    if (!inFile)
    {
        std::cerr << "Fehler beim Oeffnen der Datei: " << "ChoosedWords.txt" << '\t' << current_path_obj << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        if (!line.empty())
        {
            std::istringstream lineStream(line);
            std::string word, translation;

            // Erstes Wort vor dem Komma
            std::getline(lineStream, word, ',');

            // Zweites Wort nach dem Komma
            std::getline(lineStream, translation);

            tempVec.push_back(word);
            tempVecTrans.push_back(translation);
        }
    }

    inFile.close();

     // Prüfen, ob beide Vektoren dieselbe Länge haben
    if (tempVec.size() == tempVecTrans.size() && tempVec.size() != 0)
    {

            // Löschen der vorhandenen gameMap
            objS.gameString.clear();

            // Füllen der gameMap für jedes Fenster mit den Wörtern aus den Vektoren
            for (size_t i = 0; i < tempVec.size(); ++i)
            {
                objS.gameString[tempVec[i]] = tempVecTrans[i];
            }
    }
}

//hilfsfunktion
void loadToGameFunction(WindowDataContainer &objC, GameString &objS)
{
    auto timeSeed = std::chrono::steady_clock::now().time_since_epoch().count();
    auto seed = std::random_device{}();
    auto combinedSeed = seed ^ timeSeed;
    auto pseudoGen = std::mt19937(combinedSeed);
    auto dist = std::uniform_int_distribution<std::size_t>(0, objS.gameString.size() - 1);
    //auto dist1 = std::uniform_int_distribution<std::size_t>(0, 4);

    if (objS.gameString.size() >= 5)
    {
        std::cout << std::endl;
        short count1 = 0; //NOTE testing
        for (int i = 0; i < 5; i++)
        {
            auto genIndex = dist(pseudoGen);
            auto tempIterator = objS.gameString.begin();
            std::advance(tempIterator, genIndex);

            auto tempLambdaAccess = tempIterator->first;
            bool tempBool = std::none_of(objC.windows.begin(), objC.windows.end(), [tempLambdaAccess](const ImGuiWindowProps &windows) {return windows.title == tempLambdaAccess;});

            if (tempBool)
            {
                objC.windows[i].title = tempIterator->first;
                objC.windows[i].selectedWindow1 = true;
                objC.windows[i + 5].title = tempIterator->second;       //TODO second soll nicht immer gegenüber gesetzt werden sondern willkürlich
                objC.windows[i + 5].selectedWindow1 = true;     //TODO second soll nicht immer gegenüber gesetzt werden sondern willkürlich
            }
            else
            {
                i = 0; //NOTE <<-- Generiert alle Fenster von vorne weil eines doppelt vorkam
                for (auto item : objC.windows)
                {
                    item.selectedWindow1 = false;
                }
            }
        }
    }
}

//hilfsfunktion
void parseToJsonFuncConfig(WindowDataContainer &objC)
{
    auto filePath = std::filesystem::current_path();
    filePath /= "files";
    filePath /= "config.json";
    auto fileDir = filePath.parent_path();

    if (!std::filesystem::exists(fileDir))
    {
        std::filesystem::create_directory(fileDir);
    }

    nlohmann::json jArray = nlohmann::json::array();
    for (const auto &item : objC.DropDownWindows)
    {
        nlohmann::json tempJson;
        tempJson ["bool_values" + item.title] = item.selectedStates;
        tempJson ["selectedCount" + item.title] = item.words;
        jArray.push_back(tempJson);
    }

    nlohmann::json j;
    j = jArray;

    std::ofstream jsonConfigFile(filePath);
    if (jsonConfigFile.is_open())
    {
        jsonConfigFile << j.dump(4);
        jsonConfigFile.close();
    }
}

//hilfsfunktion
void parseFromJsonFuncConfig(const std::string &key, std::string &words, std::vector<bool> &selectedStates)
{
    auto thisPath = std::filesystem::current_path();
    thisPath /= "files";
    thisPath /= "config.json";

    if (!std::filesystem::exists(thisPath))
    {
        std::cerr << "Error, not found config.json\n";
        return;
    }

    std::ifstream tempRead(thisPath);

    if (tempRead.is_open())
    {
        nlohmann::json jObj;
        tempRead >> jObj; // Lese das Array von JSON-Objekten

            std::string keyBoolArr = "bool_values" + key;
            std::string keyCountString = "selectedCount" + key;

            for (const auto &entry : jObj)
            {
                if (entry.contains(keyBoolArr) && entry.contains(keyCountString))
                {
                        selectedStates = entry[keyBoolArr].get<std::vector<bool>>();
                        words = entry[keyCountString].get<std::string>();

                        std::cout << "config.json keys successfull found in " << key << std::endl;
                        return;
                }
                else
                {
                        std::cerr << "Error, json file doesnt contains the keywords!\n";
                }
            }

        tempRead.close();
    }
}

//hilfsfunktion
void buttonLogic(WindowDataContainer &objC, GameString &objS)
{
    std::string tempKey {};
    std::string tempValue {};
    short tempCount {};

    for (auto &item : objC.windows)
    {
        if (item.selectedWindow2)
        {
            auto tempIt = objS.gameString.find(item.title);
            if (tempIt != objS.gameString.end())
            {
               tempKey = item.title;
               tempCount++;
               item.titleClone = item.title;
               std::cout << item.titleClone << "  key" << '\n';
            }
            else
            {
                bool tempBool = false;
                for (const auto &pair : objS.gameString)
                {
                    if (pair.second == item.title)
                    {
                        tempValue = item.title;
                        tempCount++;
                        tempBool = true;
                        item.titleClone = item.title;
                        std::cout << item.titleClone << "  value" << '\n';
                        break;
                    }
                }
                if (!tempBool)
                {
                    item.titleClone = "";
                    std::cout << item.titleClone << "  void" << '\n';
                }
            }
        }
        else
        {
            item.titleClone = ""; //NOTE <<-- setzte standartmäßig diesen string zurück wenn button nicht ausgewählt (selectedWindow2)
        }
    }
    if (tempCount == 2)
    {
        auto tempIt2 = objS.gameString.find(tempKey);
        if (tempIt2->second == tempValue)
        {
            //TODO key-value rausnehmen, neu generieren und einfügen
            std::cout << "Hurra" << '\n';
            gameWindowPosLoader(objC, objS);
            newKeyValue(objC, objS);
        }
        else
        {
            //TODO key-value button abwählen weil falsches paar
            std::cout << "Wrong or not clicked" << '\n';
            wrongKeyValue(objC, objS);
        }
    }
}

//hilfsfunktion
void newKeyValue (WindowDataContainer &objC, GameString &objS)
{
     for (auto &item : objC.windows)
    {
        if(item.selectedWindow2)
        {
            item.selectedWindow1 = false;
            item.selectedWindow2 = false;
            singleGenerator(objC, objS);
        }
    }
}

//hilfsfunktion
void wrongKeyValue (WindowDataContainer &objC, GameString &objS)
{
    for (auto &item : objC.windows)
    {
        if(item.selectedWindow2)
        {
            item.selectedWindow2 = false;
        }
    }
}

//hilfsfunktion
void singleGenerator (WindowDataContainer &objC, GameString &objS)
{
    bool tempBool {};
    std::string tempStringFirst {};
    std::string tempStringSecond {};
        do
        {
            auto timeSeed = std::chrono::steady_clock::now().time_since_epoch().count();
            auto seed = std::random_device{}();
            auto combinedSeed = seed ^ timeSeed;
            auto pseudoGen = std::mt19937(combinedSeed);
            auto dist = std::uniform_int_distribution<std::size_t>(0, objS.gameString.size() - 1);
            auto singleGetIndex = dist(pseudoGen);
            auto singleTempIt = objS.gameString.begin();
            std::advance(singleTempIt, singleGetIndex);
            auto tempLambda = singleTempIt->first;
            tempBool = std::none_of(objC.windows.begin(), objC.windows.end(), [tempLambda](const ImGuiWindowProps &windows){return windows.title == tempLambda;});
            if (tempBool)
            {
                tempStringFirst = singleTempIt->first;
                tempStringSecond = singleTempIt->second;
            }
        }while (!tempBool);

    for (size_t i = 0; i < 5; i++)
    {
        if (!objC.windows[i].selectedWindow1)
        {
            objC.windows[i].title = tempStringFirst;
            objC.windows[i].selectedWindow1 = true;
            objC.windows[i + 5].title = tempStringSecond;       //TODO second soll dort gesetzt werden wo frei ist (selectedWindow1 = false)
            objC.windows[i + 5].selectedWindow1 = true;     //TODO second soll dort gesetzt werden wo frei ist (selectedWindow1 = false)
            objC.windows[i + 5].selectedWindow2 = false;        //TODO second soll dort gesetzt werden wo frei ist (selectedWindow1 = false)
        }
    }
}

//hilfsfunktion
void gameWindowPosLoader (WindowDataContainer &objC, GameString &objS)
{
    std::vector<ImVec2> gameWindowPositions (5); //NOTE <<-- 5 elemente vor-allokieren und ImVec2 Standart-Konstruktor ausführen
    for (size_t i = 5; i < 10; i++) //NOTE <<-- nur die letzten 5 elemente shufflen
    {
        gameWindowPositions[i - 5] = objC.windows[i].position;
    }
    std::random_device tempDevice;
    std::mt19937 tempTwister (tempDevice());
    std::shuffle (gameWindowPositions.begin(), gameWindowPositions.end(), tempTwister);

    for (const auto & item : gameWindowPositions) //NOTE TEST
    {
        std::cout << item.x << 't' << item.y << '\n'; //NOTE TEST
    }

    for (size_t j = 5; j < 10; j++)
    {
        objC.windows[j].position = gameWindowPositions[j - 5];
    }
}
