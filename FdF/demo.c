#include "fdf.h"

void	draw_demo(t_fdf fdf)
{
	t_point	start = {400, 300};
	
	draw_line(start, (t_point){800, 250}, fdf);
	draw_line(start, (t_point){800, 350}, fdf);
	draw_line(start, (t_point){0, 250}, fdf);
	draw_line(start, (t_point){0, 350}, fdf);
	draw_line(start, (t_point){450, 0}, fdf);
	draw_line((t_point){460,0}, (t_point){410, 300}, fdf);
	draw_line(start, (t_point){350, 0}, fdf);
	draw_line(start, (t_point){450, 600}, fdf);
	draw_line(start, (t_point){350, 600}, fdf);
	draw_line((t_point){0, 0}, (t_point){200, 200}, fdf);
}
