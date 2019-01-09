
/*
   printf( (S_ISDIR(fs.st_mode)) ? "d" : "-");
   printf( (fs.st_mode & S_IRUSR) ? "r" : "-");
   printf( (fs.st_mode & S_IWUSR) ? "w" : "-");
   printf( (fs.st_mode & S_IXUSR) ? "x" : "-");

   printf( (fs.st_mode & S_IRGRP) ? "r" : "-");
   printf( (fs.st_mode & S_IWGRP) ? "w" : "-");
   printf( (fs.st_mode & S_IXGRP) ? "x" : "-");

   printf( (fs.st_mode & S_IROTH) ? "r" : "-");
   printf( (fs.st_mode & S_IWOTH) ? "w" : "-");
   printf( (fs.st_mode & S_IXOTH) ? "x" : "-");
   */
int		error_func(void)
{
	printf("%s\n", strerror(errno));
	return (1);
}

char	*strjoin(char *s1, char *s2)
{
	char *res;
	int	l1;
	int	l2;

	l1 = strlen(s1);
	l2 = strlen(s2);
	if (!(res = (char *)malloc(sizeof(*res) * (l1 + l2 + 1))))
		return (NULL);
	bzero(res, l1 + l2 + 1);
	strcpy(res, s1);
	strcpy(res + l1, "/");
	strcpy(res + l1 + 1, s2);
	return (res);
}

int	my_ls(DIR *dirp, char *path)
{
	struct dirent *res;
	struct stat fs;
	char	*join;

	printf("%-10s\n", path);
	while ((res = readdir(dirp)))
	{
		if (res->d_name[0] != '.')
		{
			join = strjoin(path, res->d_name);
			stat(join, &fs);
			printf("%-15s", res->d_name);
		}
	}
	printf("\n");
	closedir(dirp);
	dirp = opendir(path);
	while ((res = readdir(dirp)))
		if (res->d_name[0] != '.')
		{
			join = strjoin(path, res->d_name);
			stat(join, &fs);
			if ((S_ISDIR(fs.st_mode)))
				my_ls(opendir(join), join);
		}
	if (join)
		free(join);
	return (1);
}

int	main(int argc, char **argv)
{
	DIR *dirp;
	char *path;

	path = (char *)malloc(sizeof(*path) * 80);
	if (argc < 2)
		strcat(path, "test1");
	else
		path = strcat(path, argv[1]);
	dirp = opendir(path);
	if (dirp == NULL)
		return (error_func());
	my_ls(dirp, path);
	if (closedir(dirp) == -1)
		return (error_func());
	if (path)
		free(path);
	return (0);
}
