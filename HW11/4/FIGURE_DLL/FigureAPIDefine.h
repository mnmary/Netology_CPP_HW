#pragma once
#ifdef FIGUREDLL_EXPORTS
#define FIGURE_API __declspec(dllexport)    
#else
#define FIGURE_API __declspec(dllimport)
#endif
