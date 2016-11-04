#include "defines.hpp"

class BaseStatic
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = CT_STATIC; // Control identification (without it, the control won't be displayed)
    type = CT_STATIC; // Type
    style = ST_LEFT + ST_MULTI; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 1; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    colorBackground[] = {0.2,0.2,0.2,1}; // Fill color

    text = ""; // Displayed text
    sizeEx = GUI_GRID_CENTER_H; // Text size
    font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
    shadow = 1; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
    lineSpacing = 1; // When ST_MULTI style is used, this defines distance between lines (1 is text height)
    fixedWidth = 1; // 1 (true) to enable monospace
    colorText[] = {1,1,1,1}; // Text color
    colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)

    tooltip = ""; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    moving = 0; // 1 (true) to allow dragging the whole display by the control

    autoplay = 0; // Play video automatically (only for style ST_PICTURE with text pointing to an .ogv file)
    loops = 0; // Number of video repeats (only for style ST_PICTURE with text pointing to an .ogv file)

    tileW = 1; // Number of tiles horizontally (only for style ST_TILE_PICTURE)
    tileH = 1; // Number of tiles vertically (only for style ST_TILE_PICTURE)

    onCanDestroy = "";
    onDestroy = "";
    onMouseEnter = "";
    onMouseExit = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";

    onVideoStopped = "";
};


class _ST_LEFT
{
    type = CT_STATIC;
    idc = ST_LEFT;
    style = ST_LEFT;

    x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
    y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
    w = 10 * GUI_GRID_CENTER_W;
    h = 2 * GUI_GRID_CENTER_H;

    text = "ST_LEFT";
    sizeEx = GUI_GRID_CENTER_H;
    font = GUI_FONT_NORMAL;
    lineSpacing = 1;
    colorText[] = {0,0,0,1};
    colorBackground[] = {1,0.5,0,1};
};
class _ST_RIGHT: _ST_LEFT
{
    idc = ST_RIGHT;
    style = ST_RIGHT;
    text = "ST_RIGHT";
    y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_CENTER: _ST_LEFT
{
    idc = ST_CENTER;
    style = ST_CENTER;
    text = "ST_CENTER";
    y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_MULTI: _ST_LEFT
{
    idc = ST_MULTI;
    style = ST_MULTI;
    text = "ST_MULTI\nST_MULTI";
    y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_TITLE_BAR: _ST_LEFT
{
    idc = ST_TITLE_BAR;
    style = ST_TITLE_BAR;
    text = "ST_TITLE_BAR";
    y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_PICTURE: _ST_LEFT
{
    idc = ST_PICTURE;
    style = ST_PICTURE;
    text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
    y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_PICTURE_video: _ST_LEFT
{
    idc = ST_PICTURE + 1000;
    style = ST_PICTURE;
    text = "\A3\Missions_F_Bootcamp\video\VR_BOOT.ogv";
    colorText[] = {1,1,1,1};
    y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
    w = 8 * GUI_GRID_CENTER_W;
    h = 5 * GUI_GRID_CENTER_H;

    autoplay = 1;
    loops = 1;
};
class _ST_FRAME: _ST_LEFT
{
    idc = ST_FRAME;
    style = ST_FRAME;
    text = "ST_FRAME";
    x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
    y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_BACKGROUND: _ST_FRAME
{
    idc = ST_BACKGROUND;
    style = ST_BACKGROUND;
    text = "ST_BACKGROUND";
    y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_GROUP_BOX: _ST_FRAME
{
    idc = ST_GROUP_BOX;
    style = ST_GROUP_BOX;
    text = "ST_GROUP_BOX";
    y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_GROUP_BOX2: _ST_FRAME
{
    idc = ST_GROUP_BOX2;
    style = ST_GROUP_BOX2;
    text = "ST_GROUP_BOX2";
    y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_HUD_BACKGROUND: _ST_FRAME
{
    idc = ST_HUD_BACKGROUND;
    style = ST_HUD_BACKGROUND;
    text = "ST_HUD_BACKGROUND";
    y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_TILE_PICTURE: _ST_FRAME
{
    idc = ST_TILE_PICTURE;
    style = ST_TILE_PICTURE;
    text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
    y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
    tileW = 10;
    tileH = 2;
};
class _ST_WITH_RECT: _ST_FRAME
{
    idc = ST_WITH_RECT;
    style = ST_WITH_RECT;
    text = "ST_WITH_RECT";
    y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_LINE: _ST_FRAME
{
    idc = ST_LINE;
    style = ST_LINE;
    text = "ST_LINE";
    y = 22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_UPPERCASE
{
    idc = ST_UPPERCASE;
    style = ST_UPPERCASE;
    type = CT_SHORTCUTBUTTON; // Type
    text = "st_UPPERCASE";

    x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
    y = 1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
    w = 10 * GUI_GRID_CENTER_W;
    h = 2 * GUI_GRID_CENTER_H;

    colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
    colorBackground2[] = {0,0,0,1}; // Selected fill color
    colorBackgroundFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground2)
    colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color

    size = GUI_GRID_CENTER_H; // Text size
    font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
    shadow = 1; // Shadow (0 - none, 1 - directional, color cannot be changed, 2 - black outline)
    color[] = {1,1,1,1}; // Text color
    color2[] = {1,1,1,1}; // Selected fill color
    colorFocused[] = {1,1,1,1}; // Selected text color (oscillates between this and color2)
    colorDisabled[] = {1,1,1,0.5}; // Disabled text color

    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)"; // Background texture
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)"; // Mouse over background texture
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)"; // Mouse pressed background texture
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)"; // Focused background texture
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)"; // Disabled background texture
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)"; // Unknown?

    tooltip = "CT_SHORTCUTBUTTON"; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    period = 1; // Oscillation time between color2/colorBackground2 and colorFocused/colorBackgroundFocused when selected
    periodFocus = 1; // Oscillation time between color2/colorBackground2 and colorFocused/colorBackgroundFocused when focused
    periodOver = 0.5; // Oscillation time between color2/colorBackground2 and colorFocused/colorBackgroundFocused during mouse hover

    shortcuts[] = {KEY_XBOX_A, DIK_RETURN, DIK_SPACE, DIK_NUMPADENTER}; // DIK codes of keyoboard shortcuts
    textureNoShortcut = "#(argb,8,8,3)color(1,1,1,0)"; // Icon displayed on ShortcutPos position when no shortcut key is found

    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

    class Attributes
    {
        align = "left"; // Text align
        color = "#ffffff"; // Text color
        font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
        shadow = 0; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
    };
    class HitZone // Clickable area
    {
        left = 0; // Left border
        top = 0; // Top border
        right = 0; // Right border
        bottom = 0; // Bottom border
    };
    class TextPos // Text position inside button
    {
        left = 0; // Left border
        top = 0; // Top border
        right = 0; // Right border
        bottom = 0; // Bottom border
    };
    class ShortcutPos // Shortcut icon position (e.g., XboX A button), based on keys in shortcuts[] attribute
    {
        left = 0; // Horizontal coordinates
        top = 0; // Horizontal coordinates
        w = GUI_GRID_CENTER_W; // Width
        h = GUI_GRID_CENTER_H; // Height
    };
};
class _ST_LOWERCASE: _ST_UPPERCASE
{
    idc = ST_LOWERCASE;
    style = ST_LOWERCASE;
    text = "st_LOWERCASE";
    y = 4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_SHADOW: _ST_LEFT
{
    idc = ST_SHADOW;
    style = ST_SHADOW;
    text = "ST_SHADOW";
    x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
    y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_NO_RECT: _ST_SHADOW
{
    idc = ST_NO_RECT;
    style = ST_NO_RECT;
    text = "ST_NO_RECT";
    y = 10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _ST_KEEP_ASPECT_RATIO: _ST_SHADOW
{
    idc = ST_KEEP_ASPECT_RATIO;
    style = ST_PICTURE + ST_KEEP_ASPECT_RATIO;
    text = "\A3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
    y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
};
class _SL_HORZ
{
    type = CT_SLIDER;
    idc = CT_SLIDER + SL_HORZ;
    style = SL_HORZ;

    x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 16 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    color[] = {0,0,0,1}; // Text color
    colorDisabled[] = {1,1,1,0.5}; // Disabled text color
    colorActive[] = {1,0.5,0,1}; // Text selection color

    tooltip = "SL_HORZ"; // Tooltip text
};
class _SL_VERT: _SL_HORZ
{
    idc = CT_SLIDER + SL_VERT;
    style = SL_VERT;

    x = 35 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 1 * GUI_GRID_CENTER_W; // Width
    h = 10 * GUI_GRID_CENTER_H; // Height

    tooltip = "SL_VERT"; // Tooltip text
};
class _ST_HORIZONTAL
{
    type = CT_PROGRESS;
    idc = CT_PROGRESS + ST_HORIZONTAL;
    style = ST_HORIZONTAL;

    x = 23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 18 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    texture = "#(argb,8,8,3)color(1,1,1,1)"; // Bar texture
    colorBar[] = {0,0,0,1}; // Bar color
    colorFrame[] = {0,0,0,1}; // Frame color

    tooltip = "ST_HORIZONTAL"; // Tooltip text
};
class _ST_VERTICAL: _ST_HORIZONTAL
{
    idc = CT_PROGRESS + ST_VERTICAL;
    style = ST_VERTICAL;

    x = 37 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 14 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 1 * GUI_GRID_CENTER_W; // Width
    h = 10 * GUI_GRID_CENTER_H; // Height

    tooltip = "ST_VERTICAL"; // Tooltip text
};

class BaseText : BaseStatic {
    style = ST_LEFT;
    blinkingPeriod = 0;
    colorBackground[] = {0,0,0,0};
    fixedWidth = 0;
};

class BaseTextSection: BaseText
{
    style = ST_CENTER;
    font = GUI_FONT_BOLD;
};
class BaseTextSubsection: BaseText
{
    style = ST_CENTER;
};
class BaseTextLabel: BaseText
{
    style = ST_CENTER;
    font = GUI_FONT_THIN;
};

class BaseSlider
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = CT_XSLIDER; // Control identification (without it, the control won't be displayed)
    type = CT_XSLIDER; // Type
    style = SL_HORZ; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 19 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    color[] = {1,1,1,1}; // Text and arrow color
    colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
    colorActive[] = {1,0.5,0,1}; // Text selection color

    tooltip = ""; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
    arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
    border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
    thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)


    class Title // Link to a title (obsolete?)
    {
        idc = -1; // Control IDC (has to be defined ABOVE the slider control)
        colorBase[] = {1,1,1,1}; // Text color
        colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
    };
    class Value // Link to a control which will show slider value
    {
        idc = -1; // Control IDC (has to be defined ABOVE the slider control)
        format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
        type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
        colorBase[] = {1,1,1,1}; // Text color
        colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
    };

    onCanDestroy = "";
    onDestroy = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";

    onSliderPosChanged = "";
};
class BaseList
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = CT_LISTBOX; // Control identification (without it, the control won't be displayed)
    type = CT_LISTBOX; // Type
    style = ST_LEFT + LB_TEXTURES; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 11 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 3 * GUI_GRID_CENTER_H; // Height

    colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
    colorSelectBackground[] = {1,0.5,0,1}; // Selected item fill color
    colorSelectBackground2[] = {0,0,0,1}; // Selected item fill color (oscillates between this and colorSelectBackground)

    sizeEx = GUI_GRID_CENTER_H; // Text size
    font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
    shadow = 0; // Shadow (0 - none, 1 - directional, color affected by colorShadow, 2 - black outline)
    colorText[] = {1,1,1,1}; // Text and frame color
    colorDisabled[] = {1,1,1,0.5}; // Disabled text color
    colorSelect[] = {1,1,1,1}; // Text selection color
    colorSelect2[] = {1,1,1,1}; // Text selection color (oscillates between this and colorSelect)
    colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)

    pictureColor[] = {1,0.5,0,1}; // Picture color
    pictureColorSelect[] = {1,1,1,1}; // Selected picture color
    pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

    tooltip = "CT_LISTBOX"; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    period = 1; // Oscillation time between colorSelect/colorSelectBackground2 and colorSelect2/colorSelectBackground when selected

    rowHeight = 1.5 * GUI_GRID_CENTER_H; // Row height
    itemSpacing = 0; // Height of empty space between items
    maxHistoryDelay = 1; // Time since last keyboard type search to reset it
    canDrag = 1; // 1 (true) to allow item dragging

    soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

    // Scrollbar configuration (applied only when LB_TEXTURES style is used)
    class ListScrollBar
    {
        width = 0; // Unknown?
        height = 0; // Unknown?
        scrollSpeed = 0.01; // Unknown?

        arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
        arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
        border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
        thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

        color[] = {1,1,1,1}; // Scrollbar color
    };

    onCanDestroy = "";
    onDestroy = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";

    onLBSelChanged = "";
    onLBDblClick = "";
};

class BaseListHorizontal
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = CT_XLISTBOX; // Control identification (without it, the control won't be displayed)
    type = CT_XLISTBOX; // Type
    style = SL_HORZ + ST_CENTER + LB_TEXTURES; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 17 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    color[] = {1,1,1,1}; // Arrow color
    colorActive[] = {1,0.5,0,1}; // Selected arrow color

    sizeEx = GUI_GRID_CENTER_H; // Text size
    font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
    shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
    colorText[] = {1,1,1,1}; // Text color
    colorSelect[] = {1,0.5,0,1}; // Selected text color
    colorDisabled[] = {1,1,1,0.5}; // Disabled text color

    tooltip = "CT_XLISTBOX"; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
    arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
    border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture

    soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

    onCanDestroy = "";
    onDestroy = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";

    onLBSelChanged = "";
    onLBDblClick = "";
};

class BaseCheckbox
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = CT_CHECKBOX; // Control identification (without it, the control won't be displayed)
    type = CT_CHECKBOX; // Type
    style = ST_LEFT + ST_MULTI; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 29 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 20 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 1 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    //Colors
    color[] = {1,1,1,0.7}; // Texture color
    colorFocused[] = {1,1,1,1}; // Focused texture color
    colorHover[] = {1,1,1,1}; // Mouse over texture color
    colorPressed[] = {1,1,1,1}; // Mouse pressed texture color
    colorDisabled[] = {1,1,1,0.2}; // Disabled texture color

    //Background colors
    colorBackground[] = {0,0,0,0}; // Fill color
    colorBackgroundFocused[] = {0,0,0,0}; // Focused fill color
    colorBackgroundHover[] = {0,0,0,0}; // Mouse hover fill color
    colorBackgroundPressed[] = {0,0,0,0}; // Mouse pressed fill color
    colorBackgroundDisabled[] = {0,0,0,0}; // Disabled fill color

    //Textures
    textureChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";		//Texture of checked CheckBox.
    textureUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";		//Texture of unchecked CheckBox.
    textureFocusedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";	//Texture of checked focused CheckBox (Could be used for showing different texture when focused).
    textureFocusedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";	//Texture of unchecked focused CheckBox.
    textureHoverChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureHoverUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    texturePressedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    texturePressedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    textureDisabledChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureDisabledUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";

    tooltip = ""; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    //Sounds
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

    onCanDestroy = "";
    onDestroy = "";
    onMouseEnter = "";
    onMouseExit = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";
};

class BaseButton
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = CT_XBUTTON; // Control identification (without it, the control won't be displayed)
    type = CT_XBUTTON; // Type
    style = ST_LEFT; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
    y = 15 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
    w = 10 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    colorBackground[] = {1,0.5,0,0.5}; // Fill color
    colorActiveBackground[] = {1,0.5,0,1}; // Selected fill color (rendered below colorBackground)
    colorActiveBackground2[] = {0.5,0.25,0,1}; // Selected fill color (oscillates between this and colorActiveBackground)
    colorDisabled[] = {0,1,1,1};

    text = ""; // Displayed text
    size = GUI_GRID_CENTER_H; // Text size
    font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
    shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
    color[] = {1,1,1,1}; // Text color
    colorActive[] = {1,1,1,1}; // Selected text color
    colorActive2[] = {1,1,1,1}; // Selected text color (oscillates between this and colorActive)

    tooltip = ""; // Tooltip text
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

    period = 1; // Oscillation time between colorBackground and colorFocused when selected

    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

    onCanDestroy = "";
    onDestroy = "";
    onMouseEnter = "";
    onMouseExit = "";
    onSetFocus = "";
    onKillFocus = "";
    onKeyDown = "";
    onKeyUp = "";
    onMouseButtonDown = "";
    onMouseButtonUp = "";
    onMouseButtonClick = "";
    onMouseButtonDblClick = "";
    onMouseZChanged = "";
    onMouseMoving = "";
    onMouseHolding = "";

    onButtonClick = "";
    onButtonDown = "";
    onButtonUp = "";
};