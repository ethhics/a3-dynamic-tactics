#include "basetypes.hpp"
#define MIN_MAP_SIZE 500
#define MAX_MAP_SIZE 2500

class Intel_dialog
{
    idd=42;
    movingEnable = false;
    enableSimulation = false;
    colorBackground = [0,0,0,0.5];

    class controls {
        class Section_INTEL: BaseTextSection
        {
            idc = 1000;
            text = "Intel"; //--- ToDo: Localize;
            x = 18.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 0.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_AO: BaseSlider
        {
            idc = 1010;
            tooltip = "AO Size"; //--- ToDo: Localize;
            x = 4 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 32 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [1011, str(sliderPosition 1010)]";
        };
        class Text_AO: BaseTextLabel
        {
            idc = 1011;
            style = ST_CENTER;
            text = "1000";
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        }
        class Slider_OVERCAST: BaseSlider
        {
            idc = 1020;
            tooltip = "Overcast"; //--- ToDo: Localize;
            x = 4 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 6 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 32 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [1021, str(sliderPosition 1020)]";
        };
        class Text_OVERCAST: BaseTextLabel
        {
            idc = 1021;
            style = ST_CENTER;
            text = "0.5";
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 8 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        }
        class Slider_DAYTIME: BaseSlider
        {
            idc = 1030;
            tooltip = "Time of Day"; //--- ToDo: Localize;
            x = 4 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 32 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [1031, str(sliderPosition 1030)]";
        };
        class Text_DAYTIME: BaseTextLabel
        {
            idc = 1031;
            style = ST_CENTER;
            text = "12";
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 11 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        }
        
        class Section_SITUATION: BaseTextSection
        {
            idc = 2000;
            text = "Situation"; //--- ToDo: Localize;
            x = 18 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_BLUFOR: BaseTextSubsection
        {
            idc = 2100;
            text = "BLUFOR"; //--- ToDo: Localize;
            x = 2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_BLUFOR: BaseList
        {
            idc = 2101;
            tooltip = "Situation"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 6 * GUI_GRID_CENTER_H;
        };
        class Checkbox_BLUFOR: BaseCheckbox
        {
            idc = 2102;
            tooltip = "Allied to INDFOR?"; //--- ToDo: Localize;
            x = 3 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };
        class Subsection_INDFOR: BaseTextSubsection
        {
            idc = 2200;
            text = "INDFOR"; //--- ToDo: Localize;
            x = 18 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_INDFOR: BaseList
        {
            idc = 2201;
            tooltip = "Situation"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 6 * GUI_GRID_CENTER_H;
        };
        class Subsection_OPFOR: BaseTextSubsection
        {
            idc = 2300;
            text = "OPFOR"; //--- ToDo: Localize;
            x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_OPFOR: BaseList
        {
            idc = 2301;
            tooltip = "Situation"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 6 * GUI_GRID_CENTER_H;
        };
        class Checkbox_OPFOR: BaseCheckbox
        {
            idc = 2302;
            tooltip = "Allied to INDFOR?"; //--- ToDo: Localize;
            x = 35 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };
        
        class Section_PLAYER: BaseTextSection
        {
            idc = 3000;
            text = "Player"; //--- ToDo: Localize;
            x = 18.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 3.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_PLAYCLASS: BaseListHorizontal
        {
            idc = 3010;
            tooltip = "Class"; //--- ToDo: Localize;
            x = 10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 10 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Checkbox_PLAYERLEAD: BaseCheckbox
        {
            idc = 3020;
            tooltip = "Commander?"; //--- ToDo: Localize;
            x = 21 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };
        class Text_PLAYERLEAD: BaseTextLabel
        {
            idc = 3021;
            style = ST_CENTER;
            text = "In Commanding Role";
            x = 22 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 10 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        
        class Button_NEXT: BaseButton
        {
            idc = 4000;
            text = "NEXT"; //--- ToDo: Localize;
            x = 36 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 2.5 * GUI_GRID_CENTER_H;
            onButtonClick = "intelComplete = true;";
        };
    };
};