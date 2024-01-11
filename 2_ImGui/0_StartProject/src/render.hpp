// render.hpp
#ifndef RENDER_HPP
#define RENDER_HPP

#include "imgui.h"
#include <string>
#include <vector>


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

struct VocableButtons                //TODO dropboxen bearbeiten, AtoZ & words implementieren
{
    std::string title;
    std::string AtoZ;
    std::string words;
    ImVec2 position;
    ImVec2 size;
    ImGuiWindowFlags flags;
    bool selected;


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

};

//render.hpp
void RenderMenuWindow(MenuButtons &objM);
void RenderGameWindow(WindowDataContainer &objC, MenuButtons &objM);
void RenderSettingWindow(MenuButtons &objM);
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM);
#endif // RENDER_HPP
