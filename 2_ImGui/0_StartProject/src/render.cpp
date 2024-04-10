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

    //Zum erstellen von dropdown fenstern z.B. A anklicken und alle Woerter die mit A beginnen aufzeigen

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
           takeWordsFromFile(winProps.AtoZ, winProps.wordsVec, winProps.wordsVecTranslate, winProps.selectedStates);
            for (size_t i = 0; i < winProps.wordsVec.size(); i++)
            {
                std::cout << winProps.wordsVec[i] << " ";
            }
    }
}

void ImGuiWindowProps::ButtonLogic(WindowDataContainer &objC) //TODO diese ButtonLogic so implementieren das alle Wörter willkürlich an alle windows.title Elemente des Vectors übergeben werden #include<random>
{
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
            loadToGameFunction(objC, objS); //TODO Funktion die strings aus GameString Struktur ins Spiel läd
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
            parseFromJsonFunc(objC);
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
            gameStringLoader(objC, objS);     //NOTE String lade Funktion ab hier werden die choosedWords.txt strings in die GameString geladen
            loadToGameFunction(objC, objS); //NOTE Funktion die strings aus GameString Struktur ins Spiel läd
            parseToJsonFunc(objC);          //NOTE Alle ausgewaehlten/abgewaehlten elemente/widgets der selectable fenster in .json datei speichern
        }

        // Iterieren Sie über jedes Dropdown-Fenster
        for (auto &winProps : objC.DropDownWindows)
        {
            ImGui::SetCursorPos(winProps.position);
            ImGui::SetNextItemWidth(winProps.size.x);

            if (ImGui::BeginCombo(winProps.title.c_str(), winProps.words.c_str()))
            {
                int selectedCount {}; // Zähler für ausgewählte Elemente in dieser Kategorie

                for (auto& item : objC.DropDownWindows)
                {
                    for (size_t i = 0; i < item.wordsVec.size(); ++i)
                    {
                        if (item.AtoZ == winProps.AtoZ)
                        {
                            bool isSelected = (i < item.selectedStates.size()) ? item.selectedStates[i] : false;

                            if (ImGui::Selectable(item.wordsVec[i].c_str(), &isSelected)) //NOTE <--hier wird bei klick aufs selectable-widget der wert &isSelected auf true/false gesetzt
                            {
                                if (i < item.selectedStates.size())
                                {
                                    item.selectedStates[i] = isSelected;
                                }
                            }

                            if (isSelected)
                            {
                                selectedCount++; //TODO Dieser Zaehler muss auch noch in der json datei gespeichert werden
                            }
                        }
                    }
                }

                winProps.words = std::to_string(selectedCount) + " ausgewählt"; // Anzeige der Anzahl ausgewählter Elemente //TODO beim start des programmes sollen die werte aus dem ChoosedWords.txt hier direkt implementiert werden damit nach dem neustart schonmal ausgewählte elemente wieder angezeigt werden boolJa = true; Funktion
                ImGui::EndCombo();
            }

            std::string buttonLabel = "<=Add" + winProps.title; // Generiert einen einzigartigen Label für jeden Button
            ImGui::SetCursorPos(ImVec2(winProps.position.x + 200, winProps.position.y));
            if (ImGui::Button(buttonLabel.c_str(), ImVec2(winProps.size.x - 100, winProps.size.y - 25)))
            {
                // Logik für den Button-Klick
                winProps.selectedVoc1 = true;
                objM.gameVocablesOpenAddWindow = true;
                // Zum Beispiel: Öffnen eines neuen Fensters, Ausführen einer Funktion, etc.
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
                        // Element löschen
                        winProps.wordsVec.erase(winProps.wordsVec.begin() + i);
                        winProps.wordsVecTranslate.erase(winProps.wordsVecTranslate.begin() + i);
                        winProps.selectedStates.erase(winProps.selectedStates.begin() + i);
                        // Kein i++ hier, da das nächste Element an die Stelle des gelöschten Elements rückt
                    }
                    else
                    {
                        // Nur erhöhen, wenn kein Element gelöscht wurde
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
            std::fill(std::begin(word1), std::end(word1), 0); // word1 wieder leeren
            objM.gameVocablesOpenAddWindow = false;
            parseToJsonFunc(objC); //NOTE ""
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
            std::fill(std::begin(word1), std::end(word1), 0); // word1 wieder leeren
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
                else if (item.selectedVoc1 == true) //schreibt nur Woerter für das angeklickte Add-Fenster!
                {
                    std::string inputString = {word1}; // word1 wird am Komma gesplittet um beide vectoren befüllen zu können
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
            parseToJsonFunc(objC); //NOTE ""
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
void parseToJsonFunc(WindowDataContainer &objC)
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
        tempJson ["selectedCount"] = item.words;
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
void parseFromJsonFunc(WindowDataContainer &objC)
{
    auto filePath = std::filesystem::current_path();
    filePath /= "files";
    filePath /= "config.json";

    if (!std::filesystem::exists(filePath))
    {
        std::cerr << "Error, not found config.json\n";
        return;
    }

std::ifstream tempRead(filePath);
    if (tempRead.is_open())
    {
        nlohmann::json jArray;
        tempRead >> jArray; // Lese das Array von JSON-Objekten

        for (auto &item : objC.DropDownWindows)
        {
            std::string keyBoolArr = "bool_values" + item.title;
            std::string keyCountString = "selectedCount";

            // Suche das passende JSON-Objekt basierend auf dem Schlüssel
            for (const auto &jObj : jArray)
            {
                if (jObj.contains(keyBoolArr) && jObj.contains(keyCountString))
                {
                    item.selectedStates = jObj[keyBoolArr].get<std::vector<bool>>();
                    item.words = jObj[keyCountString].get<std::string>();
                    break; // Breche die Suche ab, da das passende Objekt gefunden wurde
                }
            }
        }

        tempRead.close();
    }
    else
    {
        std::cerr << "Error opening config.json\n";
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
void newKeyValue(WindowDataContainer &objC, GameString &objS)
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
void wrongKeyValue(WindowDataContainer &objC, GameString &objS)
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
void singleGenerator(WindowDataContainer &objC, GameString &objS)
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
