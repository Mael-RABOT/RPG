/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** is_working.c
*/

#include "../include/prototype.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(is_working, is_working, .init = redirect_all_std) {
    cr_assert_str_eq("is working", "is working");
}
