#include "lem_in.h"

static int		parse_source_sink(char *s, t_data *data)
{
	if (s)
	{
		if (!strcmp(s, "##start") && !(data->info & SOURCE))
		{
			data->info |= SOURCE;
			return (1);
		}
		else if (!strcmp(s, "##start") && data->info & SOURCE)
			return (0);
		else if (!strcmp(s, "##end") && !(data->info & SINK))
		{
			data->info |= SINK;
			return (1);
		}
		else if (!strcmp(s, "##end") && data->info & SINK)
			return (0);
		return (0);
	}
	else
		return (0);
}

int				check_hash(t_data *data, char *s)
{
	if (s)
	{
		if (s[0] == '#' && s[1] == '#')
		{
			if ((data->info & SOURCE && !data->source) || (data->info & SINK && !data->sink))
				return (0);
			if (parse_source_sink(s, data) == 0)
				return (0);
		}
		else if (s[0] == '#' && s[1] != '#')
		{
			return (1);
		}
		return (1);
	}
	else
		return (0);
}
