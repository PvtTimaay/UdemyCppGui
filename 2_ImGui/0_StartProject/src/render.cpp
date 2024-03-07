// render.cpp
#include "render.hpp"
#include <algorithm>
#include <sstream>
#include <filesystem>
#include <random>

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
    for (auto &item : objC.windows)                        //NOTE maybe use Stuctured Binding
    {

    }
}

void RenderMenuWindow(WindowDataContainer &objC, MenuButtons &objM, GameString &objS)
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
            //TODO boolJa = true; Funktion                                         <-- TODO
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
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM, GameString &objS) {
    if (objM.gameVocables)
    {
        ImGui::SetNextWindowSize(ImVec2(1280, 720));
        ImGui::SetNextWindowPos(ImVec2(1, 1), ImGuiCond_Once);
        ImGui::Begin("Vokabeln");
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
            gameStringLoader(objC, objS);     //TODO String lade Funktion ab hier werden die choosedWords.txt strings in die GameString geladen
            loadToGameFunction(objC, objS); //TODO Funktion die strings aus GameString Struktur ins Spiel läd
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

                            if (ImGui::Selectable(item.wordsVec[i].c_str(), &isSelected))
                            {
                                if (i < item.selectedStates.size())
                                {
                                    item.selectedStates[i] = isSelected;
                                }
                            }

                            if (isSelected)
                            {
                                selectedCount++; // Aktualisieren Sie den Zähler für ausgewählte Elemente
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

//render.cpp
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

//render.cpp
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
        }
        ImGui::End();
    }
}

//render.cpp
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

//render.cpp
//hilfsfunktion
void loadToGameFunction(WindowDataContainer &objC, GameString &objS)
{
    auto timeSeed = std::chrono::steady_clock::now().time_since_epoch().count();
    auto seed = std::random_device{}();
    auto combinedSeed = seed ^ timeSeed;
    auto pseudoGen = std::mt19937(combinedSeed);
    auto dist = std::uniform_int_distribution<std::size_t>(0, objS.gameString.size() - 1);

    if (objS.gameString.size() >= 5)
    {
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
                objC.windows[i + 5].title = tempIterator->second;
                objC.windows[i].selectedWindow1 = true;
            }                                                  //TODO <- else() wenn wert zweimal vorkam soll index erneut generiert und wenns passt dann verwendet werden um alle fenster zu befüllen aber vorher prüfen ob gameString min 5 elemente lang ist
        }
    }
}
