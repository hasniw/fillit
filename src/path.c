#include "lem_in.h"

int				add_path(t_path **path, int vertex)
{
	if (!(*path))
	{
		if (!(*path = init_path(vertex)))
			return (0);
	}
	else
	{
		if (!(push_vertex(path, vertex)))
			return (0);
	}
	return (1);
}

int				number_of_path(char *map, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (map[i] == '2')
			count++;
		i++;
	}
	return (count);
}

int				first_path(char *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (map[i] == '2')
			return (i);
		i++;
	}
	return (0);
}

static int		find_source(char *map, int u, int v, t_path **path)
{
	int i;
	int size;
	static int size_path = 0;
	int tmp;

	tmp = 0;
	size = ft_sqrt(ft_strlen(map));
	if (u == size - 1)
	{
		tmp = size_path;
		size_path = 0;
		// printf("seg3 : %d %d\n", u, v);
		if (!(add_path(path, u)))
			return (0);
		// printf("seg4\n");
		return (tmp);
	}
	i = 0;
	while (i < size)
	{
		if (map[size * u + i] == '2' && i != v)
		{
			size_path++;
			// printf("value of u : %d\n", u);
			if (!(add_path(path, u)))
				return (0);
			return (find_source(map, i, u, path));
		}
		i++;
	} 
	return (1);
}

int				get_one_path(int start, t_flow **flow, char *map)
{
	t_path	*path;
	int		size_path;

	path = NULL;
	size_path = find_source(map, start, 0, &path);
	if (!(*flow))
		*flow = new_flow(path, size_path);
	else
		add_flow(flow, new_flow(path, size_path));
	return (1);
}
