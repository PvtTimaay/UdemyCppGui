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

WindowDataContainer();
};

struct ImGuiWindowProps
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
    //TODO Du brauchst eine methode die da diese xD, logik für die einzelnen ingame buttons implementieren kann
    std::string ButtonLogic(std::string){};
};

struct MenuButtons
{
    bool gameStarted = false;
    bool gameSettings = false;
    bool gameVocables = false;
    bool gameExit = false;
};

struct SettingButtons
{
    bool gameAudio = false;
    bool gameVideo = false;
    bool gameGame = false; // <- :D
};
//render.hpp
struct VocableButtons
{
    std::string title;
    std::string AtoZ;
    std::string words;
    ImVec2 position;
    ImVec2 size;
    ImGuiWindowFlags flags;


    VocableButtons(const std::string &title,
                   const std::string &AtoZ,
                   const std::string &words,
                   ImVec2 position,
                   ImVec2 size,
                   ImGuiWindowFlags flags = 0)
        : title(title), AtoZ(AtoZ), words(words), position(position), size(size), flags(flags)
    {
    }
};


void RenderMenuWindow(MenuButtons &objM);
void RenderGameWindow(WindowDataContainer &objC, MenuButtons &objM, bool &backMenu);
void RenderSettingWindow(SettingButtons &objS, MenuButtons &objM, bool &backMenu);
void RenderVocableWindow(WindowDataContainer &objC, MenuButtons &objM, bool &backMenu);
#endif // RENDER_HPP
