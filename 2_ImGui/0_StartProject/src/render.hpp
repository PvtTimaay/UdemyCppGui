// render.hpp
#ifndef RENDER_HPP
#define RENDER_HPP

#include "imgui.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>


struct ImGuiWindowProps;
struct VocableButtons;      // <- prototypen für class WindowDataContainer
class WindowDataContainer{
public:
std::vector<ImGuiWindowProps> windows;
std::vector<VocableButtons> DropDownWindows;
int item_current_idx;

WindowDataContainer();
};

struct ImGuiWindowProps     	    //TODO Du brauchst eine methode die da diese xD, logik für die einzelnen ingame buttons implementieren kann
{
    std::string title;
    ImVec2 position;
    ImVec2 size;
    ImGuiWindowFlags flags;
    bool isSelected;


    ImGuiWindowProps(const std::string &title, ImVec2 position, ImVec2 size, ImGuiWindowFlags flags = 0)
        : title(title), position(position), size(size), flags(flags), isSelected(false)
    {
    }

    std::string ButtonLogic(std::string){};
};

struct VocableButtons
{
    std::string title;
    std::string AtoZ;
    std::string words;
    ImVec2 position;
    ImVec2 size;
    ImGuiWindowFlags flags;
    bool selected;
    std::unordered_map<std::string, std::string> map;
    std::vector<std::string> wordsVec; //TODO ich brauche eine methode in VocableButtons die verschiedene wörter in einem vector speichert und diese werden dann in der RenderVocableWindow in den zum objekt gehörigen drop down boxen angezeigt!
    std::vector<std::string> wordsVecTranslate;
    std::vector<bool> selectedStates;   // ImGui::Selected(is_selected_vector_bool)

    VocableButtons(const std::string &title,
                   const std::string &AtoZ,
                   const std::string &words,
                   ImVec2 position,
                   ImVec2 size,
                   ImGuiWindowFlags flags = 0,
                   bool selected = false)
        : title(title), AtoZ(AtoZ), words(words), position(position), size(size), flags(flags), selected(selected)
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

};

//render.hpp
void RenderMenuWindow(MenuButtons &objM);
void RenderGameWindow(WindowDataContainer &objC, MenuButtons &objM);
void RenderSettingWindow(MenuButtons &objM);
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM);

//hilfsfunktionen
void saveWordsToFile(const std::vector<std::string>& wordsVec, const std::vector<std::string>& wordsVecTranslate, const std::string& filePath);
void takeWordsFromFile(const std::string& filePath, std::vector<std::string>& wordsVec, std::vector<std::string>& wordsVecTranslate, std::vector<bool>& selectedStates);
void gameVocablesApplyFunction(WindowDataContainer& objC, MenuButtons& objM);


#endif // RENDER_HPP
