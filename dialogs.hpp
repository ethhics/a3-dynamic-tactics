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
        class Checkbox_AO: BaseCheckbox
        {
            idc = 1012;
            tooltip = "Random AO Size?"; //--- ToDo: Localize;
            x = 36 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onMouseButtonClick = "ctrlEnable [1010, not cbChecked (_this select 0)];";
        };
        class Text_AOCHECKBOX: BaseTextLabel
        {
            idc = 1013;
            style = ST_CENTER;
            text = "RANDOM";
            x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 2 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
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
        class Checkbox_OVERCAST: BaseCheckbox
        {
            idc = 1022;
            tooltip = "Random Overcast?"; //--- ToDo: Localize;
            x = 36 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 6 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onMouseButtonClick = "ctrlEnable [1020, not cbChecked (_this select 0)];";
        };
        class Text_OVERCASTCHECKBOX: BaseTextLabel
        {
            idc = 1023;
            style = ST_CENTER;
            text = "RANDOM";
            x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
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
        class Checkbox_DAYTIME: BaseCheckbox
        {
            idc = 1032;
            tooltip = "Random Time of Day?"; //--- ToDo: Localize;
            x = 36 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onMouseButtonClick = "ctrlEnable [1030, not cbChecked (_this select 0)];";
        };
        class Text_DAYTIMECHECKBOX: BaseTextLabel
        {
            idc = 1033;
            style = ST_CENTER;
            text = "RANDOM";
            x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 8 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        
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

class Units_dialog
{
    idd=43;
    movingEnable = false;
    enableSimulation = false;
    colorBackground = [0,0,0,0.5];

    class controls {
        class Section_UNITS: BaseTextSection
        {
            idc = 1000;
            text = "Units"; //--- ToDo: Localize;
            x = 18.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_U_BLUFOR: BaseTextSubsection
        {
            idc = 1100;
            text = "BLUFOR"; //--- ToDo: Localize;
            x = 2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 1.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_BLUFOR: BaseList
        {
            idc = 1101;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 2.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 8 * GUI_GRID_CENTER_H;
            tooltip = "Number of Units"; //--- ToDo: Localize;
        };
        class Subsection_U_INDFOR: BaseTextSubsection
        {
            idc = 1200;
            text = "INDFOR"; //--- ToDo: Localize;
            x = 18 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 1.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_INDFOR: BaseList
        {
            idc = 1201;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 2.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 8 * GUI_GRID_CENTER_H;
            tooltip = "Number of Units"; //--- ToDo: Localize;
        };
        class Subsection_U_OPFOR: BaseTextSubsection
        {
            idc = 1300;
            text = "OPFOR"; //--- ToDo: Localize;
            x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 1.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class List_OPFOR: BaseList
        {
            idc = 1301;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 2.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 8 * GUI_GRID_CENTER_H;
            tooltip = "Number of Units"; //--- ToDo: Localize;
        };
        
        class Section_COMPOSITION: BaseTextSection
        {
            idc = 2000;
            text = "Composition"; //--- ToDo: Localize;
            x = 17.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 10.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_C_BLUFOR: BaseTextSubsection
        {
            idc = 2100;
            text = "BLUFOR"; //--- ToDo: Localize;
            x = 2 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_B0: BaseSlider
        {
            idc = 2110;
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2111, str(sliderPosition 2110)]";
        };
        class Label_B0: BaseTextLabel
        {
            idc = 2111;
            text = "0.5"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_B1: BaseSlider
        {
            idc = 2120;
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2121, str(sliderPosition 2120)]";
        };
        class Label_B1: BaseTextLabel
        {
            idc = 2121;
            text = "80"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_B2: BaseSlider
        {
            idc = 2130;
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2131, str(sliderPosition 2130)]";
        };
        class Label_B2: BaseTextLabel
        {
            idc = 2131;
            text = "2.5"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 17 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_B3: BaseSlider
        {
            idc = 2140;
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2141, str(sliderPosition 2140)]";
        };
        class Label_B3: BaseTextLabel
        {
            idc = 2141;
            text = "7"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_B4: BaseSlider
        {
            idc = 2150;
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2151, str(sliderPosition 2150)]";
        };
        class Label_B4: BaseTextLabel
        {
            idc = 2151;
            text = "5"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_B5: BaseSlider
        {
            idc = 2160;
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2161, str(sliderPosition 2160)]";
        };
        class Label_B5: BaseTextLabel
        {
            idc = 2161;
            text = "5"; //--- ToDo: Localize;
            x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_C_INDFOR: BaseTextSubsection
        {
            idc = 2200;
            text = "INDFOR"; //--- ToDo: Localize;
            x = 18 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_I0: BaseSlider
        {
            idc = 2210;
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2211, str(sliderPosition 2210)]";
        };
        class Label_I0: BaseTextLabel
        {
            idc = 2211;
            text = "0.5"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_I1: BaseSlider
        {
            idc = 2220;
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2221, str(sliderPosition 2220)]";
        };
        class Label_I1: BaseTextLabel
        {
            idc = 2221;
            text = "80"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_I2: BaseSlider
        {
            idc = 2230;
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2231, str(sliderPosition 2230)]";
        };
        class Label_I2: BaseTextLabel
        {
            idc = 2231;
            text = "2.5"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 17 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_I3: BaseSlider
        {
            idc = 2240;
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2241, str(sliderPosition 2240)]";
        };
        class Label_I3: BaseTextLabel
        {
            idc = 2241;
            text = "7"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_I4: BaseSlider
        {
            idc = 2250;
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2251, str(sliderPosition 2250)]";
        };
        class Label_I4: BaseTextLabel
        {
            idc = 2251;
            text = "5"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_I5: BaseSlider
        {
            idc = 2260;
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2261, str(sliderPosition 2260)]";
        };
        class Label_I5: BaseTextLabel
        {
            idc = 2261;
            text = "5"; //--- ToDo: Localize;
            x = 17 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_C_OPFOR: BaseTextSubsection
        {
            idc = 2300;
            text = "OPFOR"; //--- ToDo: Localize;
            x = 34 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 12 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_O0: BaseSlider
        {
            idc = 2310;
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2311, str(sliderPosition 2310)]";
        };
        class Label_O0: BaseTextLabel
        {
            idc = 2311;
            text = "0.5"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_O1: BaseSlider
        {
            idc = 2320;
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2321, str(sliderPosition 2320)]";
        };
        class Label_O1: BaseTextLabel
        {
            idc = 2321;
            text = "80"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_O2: BaseSlider
        {
            idc = 2330;
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2331, str(sliderPosition 2330)]";
        };
        class Label_O2: BaseTextLabel
        {
            idc = 2331;
            text = "2.5"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 17 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_O3: BaseSlider
        {
            idc = 2340;
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2341, str(sliderPosition 2340)]";
        };
        class Label_O3: BaseTextLabel
        {
            idc = 2341;
            text = "7"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_O4: BaseSlider
        {
            idc = 2350;
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2351, str(sliderPosition 2350)]";
        };
        class Label_O4: BaseTextLabel
        {
            idc = 2351;
            text = "5"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 21 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Slider_O5: BaseSlider
        {
            idc = 2360;
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 8 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
            onSliderPosChanged = "ctrlSetText [2361, str(sliderPosition 2360)]";
        };
        class Label_O5: BaseTextLabel
        {
            idc = 2361;
            text = "5"; //--- ToDo: Localize;
            x = 33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 23 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 6 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        
        class Subsection_L0: BaseTextSubsection
        {
            idc = 3000;
            text = "Armored"; //--- ToDo: Localize;
            x = 10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_L1: BaseTextSubsection
        {
            idc = 3001;
            text = "Infantry"; //--- ToDo: Localize;
            x = 10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_L2: BaseTextSubsection
        {
            idc = 3002;
            text = "Mechanized"; //--- ToDo: Localize;
            x = 9.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_L3: BaseTextSubsection
        {
            idc = 3003;
            text = "Motorized"; //--- ToDo: Localize;
            x = 10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_L4: BaseTextSubsection
        {
            idc = 3004;
            text = "SpecOps"; //--- ToDo: Localize;
            x = 10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_L5: BaseTextSubsection
        {
            idc = 3005;
            text = "Support"; //--- ToDo: Localize;
            x = 10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_R0: BaseTextSubsection
        {
            idc = 3100;
            text = "Armored"; //--- ToDo: Localize;
            x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_R1: BaseTextSubsection
        {
            idc = 3101;
            text = "Infantry"; //--- ToDo: Localize;
            x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_R2: BaseTextSubsection
        {
            idc = 3102;
            text = "Mechanized"; //--- ToDo: Localize;
            x = 25.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_R3: BaseTextSubsection
        {
            idc = 3103;
            text = "Motorized"; //--- ToDo: Localize;
            x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_R4: BaseTextSubsection
        {
            idc = 3104;
            text = "SpecOps"; //--- ToDo: Localize;
            x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Subsection_R5: BaseTextSubsection
        {
            idc = 3105;
            text = "Support"; //--- ToDo: Localize;
            x = 26 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 24 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        
        class Checkbox_C_BLUFOR: BaseCheckbox
        {
            idc = 2101;
            tooltip = "Random BLUFOR Composition?"; //--- ToDo: Localize;
            x = 4 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onMouseButtonClick = "\
            ctrlEnable [2110, not cbChecked (_this select 0)];\
            ctrlEnable [2120, not cbChecked (_this select 0)];\
            ctrlEnable [2130, not cbChecked (_this select 0)];\
            ctrlEnable [2140, not cbChecked (_this select 0)];\
            ctrlEnable [2150, not cbChecked (_this select 0)];\
            ctrlEnable [2160, not cbChecked (_this select 0)];\
            ";
        };
        class Text_C_BLUFORCHECKBOX: BaseTextLabel
        {
            idc = 2102;
            style = ST_RIGHT;
            text = "RANDOM";
            x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Checkbox_C_INDFOR: BaseCheckbox
        {
            idc = 2201;
            tooltip = "Random INDFOR Composition?"; //--- ToDo: Localize;
            x = 20 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onMouseButtonClick = "\
            ctrlEnable [2210, not cbChecked (_this select 0)];\
            ctrlEnable [2220, not cbChecked (_this select 0)];\
            ctrlEnable [2230, not cbChecked (_this select 0)];\
            ctrlEnable [2240, not cbChecked (_this select 0)];\
            ctrlEnable [2250, not cbChecked (_this select 0)];\
            ctrlEnable [2260, not cbChecked (_this select 0)];\
            ";
        };
        class Text_C_INDFORCHECKBOX: BaseTextLabel
        {
            idc = 2202;
            style = ST_RIGHT;
            text = "RANDOM";
            x = 16 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Checkbox_C_OPFOR: BaseCheckbox
        {
            idc = 2301;
            tooltip = "Random OPFOR Composition?"; //--- ToDo: Localize;
            x = 36 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 2 * GUI_GRID_CENTER_W;
            h = 2 * GUI_GRID_CENTER_H;
            onMouseButtonClick = "\
            ctrlEnable [2310, not cbChecked (_this select 0)];\
            ctrlEnable [2320, not cbChecked (_this select 0)];\
            ctrlEnable [2330, not cbChecked (_this select 0)];\
            ctrlEnable [2340, not cbChecked (_this select 0)];\
            ctrlEnable [2350, not cbChecked (_this select 0)];\
            ctrlEnable [2360, not cbChecked (_this select 0)];\
            ";
        };
        class Text_C_OPFORCHECKBOX: BaseTextLabel
        {
            idc = 2302;
            style = ST_RIGHT;
            text = "RANDOM";
            x = 32 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        
        class Button_GENERATE: BaseButton
        {
            idc = 4000;
            text = "Generate"; //--- ToDo: Localize;
            x = 42 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
            y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
            w = 4 * GUI_GRID_CENTER_W;
            h = 2.5 * GUI_GRID_CENTER_H;
            onButtonClick = "unitsComplete = true;";
        };
    };
};