/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 3;        /* border pixel of windows */
static const unsigned int snap     = 32;       /* snap pixel */
static const unsigned int gappx     = 8;        /* gap pixel between windows */
static const int showbar           = 1;        /* 0 means no bar */
static const int topbar            = 1;        /* 0 means bottom bar */
//static const char *fonts[]         = { "3270Medium Nerd Font Mono:size=16" };
static const char *fonts[]         = {  "FontAwesome:size=16","3270Medium Nerd Font Mono:size=16"};
static const char dmenuprompt[] 	= "Cmd>> ";
static const char dmenulines[] 		= "20";
static const char dmenufont[]      = "3270Medium Nerd Font Mono:size=16";
static const char normbgcol[]      = "#000000"; /* fond bar */
static const char normfgcol[]      = "#a0a0a0"; /* text bar */
static const char normborder[]     = "#efefef";	/* bordure autour fenetre inactive */
static const char selborder[]      = "#ff5f08";	/* bordure autour fenetre active */
static const char selbgcol[]       = "#000000"; /* fond bar active menu et tab */
static const char selfgcol[]       = "#ff5f08";	/* text bar active menu et tab */
static const char *colors[][3]     = {
	/*               fg         bg         border   */
	[SchemeNorm] = { normfgcol, normbgcol, normborder },
	[SchemeSel]  = { selfgcol,  selbgcol,  selborder  },
};
static const Bool showsystray = True;           /* False means no systray */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     		NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  		NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Update-manager", NULL, 		NULL,		0,          True,	  	-1 },
	{ "KeePassXC",		NULL,		NULL,		0,			1,			-1},
};

/* layout(s) */
static const float mfact      = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */
static const int attachdirection = 4;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-p", dmenuprompt, "-l", dmenulines, "-fn", dmenufont, "-nb", normbgcol, "-nf", normfgcol, "-sb", selbgcol, "-sf", selfgcol, NULL };
static const char *termcmd[]  = { "x-terminal-emulator", "-e", "terminal.sh", NULL };
static const char *voldown[]  = { "audio","-",NULL };
static const char *volup[]    = { "audio","+",NULL };
static const char *volmute[]  = { "audio","m",NULL };
static const char *filemanager[] = { "x-file-manager",NULL };
static const char *prev[] = { "audio","p",NULL };
static const char *next[] = { "audio","n",NULL };
static const char *play[] = { "audio","g",NULL };
static const char *browser[] = { "x-www-browser", NULL };
static const char *slock[] = { "slock", NULL };
static const char *screenshot[] = { "myScreenshot", NULL };
static const char *passwordmngt[] = { "keepassxc", NULL } ;



static Key keys[] = {
	/* modifier                     key           function        argument */
	{ 0,							0x1008ff17,	  spawn,	      {.v = next} },
	{ ControlMask,					XK_F6,		  spawn,	      {.v = next} },
	{ 0,							0x1008ff16,	  spawn,	      {.v = prev} },
	{ ControlMask,					XK_F4,		  spawn,	      {.v = prev} },
	{ 0,							0x1008ff14,	  spawn,	      {.v = play} },
	{ ControlMask,					XK_F5,		  spawn,	      {.v = play} },
	{ 0,							0x1008ff11,	  spawn,	      {.v = voldown} },
	{ ControlMask,					XK_F2,		  spawn,	      {.v = voldown} },
	{ 0,							0x1008ff13,	  spawn,	      {.v = volup} },
	{ ControlMask,					XK_F3,		  spawn,	      {.v = volup} },
	{ 0,							0x1008ff12,	  spawn,	      {.v = volmute} },
	{ ControlMask,					XK_F1,		  spawn,	      {.v = volmute} },
	{ 0,							XK_Print,	  spawn,	      {.v = screenshot} },
	{ MODKEY,                       XK_p,         spawn,          {.v = passwordmngt } },
	{ MODKEY,                       XK_s,  	      spawn,          {.v = slock } },
	{ MODKEY,                       XK_space,     spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,    spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_e,         spawn,          {.v = filemanager } },
	{ MODKEY,                       XK_g,         spawn,          {.v = browser } },
	{ MODKEY,                       XK_b,         togglebar,      {0} },
	{ MODKEY,                       XK_Tab,       focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,       focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,         incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,         incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,         setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,         setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,    zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,         killclient,     {0} },
	{ MODKEY,                       XK_t,         setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,         setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,         setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,     togglefloating, {0} },
	{ MODKEY,                       XK_0,         view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,         tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_semicolon, focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_comma,     focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_F1,                        0)
	TAGKEYS(                        XK_F2,                        1)
	TAGKEYS(                        XK_F3,                        2)
	TAGKEYS(                        XK_F4,                        3)
	TAGKEYS(                        XK_F5,                        4)
	TAGKEYS(                        XK_F6,                        5)
	TAGKEYS(                        XK_F7,                        6)
	TAGKEYS(                        XK_F8,                        7)
	TAGKEYS(                        XK_F9,                        8)
	{ MODKEY|ShiftMask,             XK_q,         quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

