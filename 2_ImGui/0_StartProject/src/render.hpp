// render.hpp
#ifndef RENDER_HPP
#define RENDER_HPP

#include "imgui.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <map>


struct ImGuiWindowProps;
struct VocableButtons;      // <- prototypen für class WindowDataContainer
class WindowDataContainer
{
    public:
    std::vector<ImGuiWindowProps> windows;
    std::vector<VocableButtons> DropDownWindows;
    int item_current_idx;

    WindowDataContainer();
};

struct ImGuiWindowProps
{
    std::string title;
    std::string titleClone; //NOTE <-- Ingame Button Logic Helper
    ImVec2 position;
    ImVec2 size;
    ImGuiWindowFlags flags;
    bool selectedWindow1;
    bool selectedWindow2;

    ImGuiWindowProps(const std::string &title, ImVec2 position, ImVec2 size, ImGuiWindowFlags flags)
        : title(title), titleClone(titleClone), position(position), size(size), flags(flags), selectedWindow1(false), selectedWindow2(false)
    {
    }
};

struct VocableButtons
{
    std::string title;
    std::string AtoZ;
    std::string words;
    ImVec2 position;
    ImVec2 size;
    ImGuiWindowFlags flags;
    bool selectedVoc1;    //NOTE ButtonLogik fuer den button der AddFunktion setzt true wenn dieser gedrückt wird
    std::vector<std::string> wordsVec;
    std::vector<std::string> wordsVecTranslate;
    std::vector<bool> selectedStates {};  //NOTE ImGui::Selected(is_selected_vector_bool)

    VocableButtons(const std::string &title,
                   const std::string &AtoZ,
                   const std::string &words,
                   ImVec2 position,
                   ImVec2 size,
                   ImGuiWindowFlags flags = 0,
                   bool selectedVoc1 = false)
        : title(title), AtoZ(AtoZ), words(words), position(position), size(size), flags(flags), selectedVoc1(selectedVoc1)
    {
    }
   void addWord(const std::string& word, const std::string& wordTrans){
        wordsVec.push_back(word);
        wordsVecTranslate.push_back(wordTrans);
        selectedStates.push_back(false);
    }

};

struct MenuButtons
{
    bool gameStarted = false;
    bool gameSettings = false;
    bool gameVocables = false;
    bool gameExit = false;
    bool gameAudio = false;
    bool gameVideo = false;
    bool gameGameplay = false;
    bool ZurueckMenue = false;
    bool gameVocablesApplyFunc = false;
    bool gameVocablesOpenAddWindow = false;

    //Laufzeit nutzungs Variablen
    std::string vocableSelectAll {"All"};
};

struct GameString       //TODO implementiere eine neue Structur die die daten aus ChoosedWords.txt in ein std::map sichert
{
    std::map<std::string, std::string> gameString {};
};

//render.hpp
void RenderMenuWindow (WindowDataContainer &objC, MenuButtons &objM, GameString &objS);
void RenderGameWindow (WindowDataContainer &objC, MenuButtons &objM, GameString &objS);
void RenderSettingWindow (MenuButtons &objM);
void RenderVocableWindow (WindowDataContainer &objC, MenuButtons &objM, GameString &objS);

//hilfsfunktionen
void saveWordsToFile (const std::vector<std::string>& wordsVec, const std::vector<std::string>& wordsVecTranslate, const std::string& filePath);    //NOTE <<-- Sollen durch Json Dateien ersetzt werden siehe parseToJsonFuncWords und parseFromJsonFuncWords
void takeWordsFromFile (const std::string& filePath, std::vector<std::string>& wordsVec, std::vector<std::string>& wordsVecTranslate, std::vector<bool>& selectedStates);   //NOTE <<-- Sollen durch Json Dateien ersetzt werden siehe parseToJsonFuncWords und parseFromJsonFuncWords
void takeWordsFromFileObject(WindowDataContainer &objC); //NOTE REFACTORY TEST! //NOTE <<-- Sollen durch Json Dateien ersetzt werden siehe parseToJsonFuncWords und parseFromJsonFuncWords
void parseToJsonFuncConfig (WindowDataContainer &objC);
void parseFromJsonFuncConfig (const std::string &key, std::string &words, std::vector<bool> &selectedStates);
void parseToJsonFuncWords (WindowDataContainer &objC);                 //NOTE <<-- funktion sollte soweit funktionieren und in allen notwenigen buttons integriert sein (TODO erstelle Json dateien zum speichern der words A-Z und ersetze die .txt dateien)
void parseFromJsonFuncWords (const std::string& filePath, std::vector<std::string>& wordsVec, std::vector<std::string>& wordsVecTranslate);                                     //TODO <<-- erstelle Json dateien zum speichern der words A-Z und ersetze die .txt dateien
void gameVocablesApplyFunction (WindowDataContainer& objC, MenuButtons& objM);
void gameVocablesAddFunction (WindowDataContainer &objC, MenuButtons &objM);
void gameStringLoader (WindowDataContainer &objC, GameString &objS);
void loadToGameFunction (WindowDataContainer &objC, GameString &objS);
void buttonLogic (WindowDataContainer &objC, GameString &objS);
void newKeyValue (WindowDataContainer &objC, GameString &objS); //TODO <<-- function for "Hurra"
void wrongKeyValue (WindowDataContainer &objC, GameString &objS); //TODO <<-- function for "wrong"
void singleGenerator (WindowDataContainer &objC, GameString &objS); //NOTE <<-- wie loadToGameFunction, generiert aber nur für ein key/value paar
void gameWindowPosLoader (WindowDataContainer &objC, GameString &objS);
#endif // RENDER_HPP
