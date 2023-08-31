/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:27:11 by dvidal-l          #+#    #+#             */
/*   Updated: 2023/08/26 13:27:16 by dvidal-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H
# define DICTIONARY "numbers.dict"
# define FAIL -1
# define SUCCESS 0
# define MAX_INT_SIZE 10
# define ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "data.h"
# include "utils.h"

/*
** Receives the path to the new dictionary and opens it with c function open
*/
int		check_arguments(char *str_num, char *dic_path, unsigned int *number,
			t_map *map);

/*
** Opens the ddictionary passed in path with function open and returns the 
** file descriptor
*/
int		open_dictionary(char *path);

/*
** Calls function open_dictionary. If thi fails returns FAIL (-1). Otherwise
** calls function read dictionary
*/
int		create_dictionary(char *path, t_map *map);

/*
** Reads the contents of dictionary which is a file whose file descrriptor is 
** stored in fd. Checks if the values are correct and stores them in a map 
** (key, value)
*/
int		read_dictionary(int fd, t_map *map);

/*
** Initializes the map used to store the values in dictionary and the data 
** used to store those values
*/
void	init(int *j, t_map *map, t_data *data);

/*
** Receives the string number, its length (len) and its corresponding int 
** value (num). This is the number to be written. Receives map, the dictionary.
** Returns FAIL if an error occurs
*/
int		translate_number(char *number, t_map map, int len, unsigned int num);

/*
** Receives the string number with the number it has to translate and its 
** length (len) and the map to translate it to text
*/
int		translate_number_aux(char *number, t_map map, int len);

/*
** Auxiliary function to print hundred numbers such as one hundred, two 
** hundred, etc.
*/
void	print_hundreds_aux(char *number, t_map map, int len, unsigned int num);

/*
** This function receives the file descriptor (fd) and attempts to read
** the int value, if is is succesfull it's stored in data.key
*/
int		read_key(int fd, t_data *data, char *c);

/*
** Ignores the spaces and ':' between the key value and the string value in 
** the dictionary
*/
int		pass_through(char *c, int fd);

/*
** Reads the string value of the corresponding key and stores it in data.value
*/
int		read_value(t_data *data, char *c, int fd);

/*
** Prints numbers with a maximum length of 3 (between 0 and 999)
*/
void	print_hundreds(char *number, t_map map, int len, unsigned int num);

/*
** Applies a binary search to the map to find the value of num.
** It searches in the range bewteen ini and end which are initially 0 and 
** map.size - 1
*/
char	*binary_search(unsigned int num, t_map map, int ini, int end);

#endif