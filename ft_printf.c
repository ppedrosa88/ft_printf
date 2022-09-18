/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppedrosa <ppedrosa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:52:15 by ppedrosa          #+#    #+#             */
/*   Updated: 2022/09/15 19:52:15 by ppedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

void ft_printf(char *format, ...){
    va_list ap;
    va_start(ap, format);
    print(format, ap);
    va_end(ap);
}

void print(char *format, va_list ap){

    char *p, *stringValue;
    int intValue;
    double doubleValue;
    char    charValue;

    for(p = format; *p; p++){
        if(*p != '%'){
            ft_putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
               intValue = va_arg(ap, int);
                printf("%d", intValue);
                break;
            case 'f':
                doubleValue = va_arg(ap, double);
                printf("%f", doubleValue);
                break;
            case 's':
            stringValue = va_arg(ap, char *)
                while(stringValue != NULL){
                    //transformar el for de debajo
                }

                for(; *stringValue; stringValue++){
                    ft_putchar(*stringValue);
                }
                break;
            case 'c':
                charValue = va_arg(ap, int);
                ft_putchar(charValue);
                break;
            default:
                ft_putchar(*p);
                break;
        }
    }
}

int main(){

  //  void *pointer_to_main = (void *) main;

    ft_printf("Imprimir un caracter: %c. Done!\n", 'H');
    ft_printf("Imprimir un String: %s. Done!\n", "Hola mundo");
    ft_printf("Imprimir un entero negativo: %d. Done!\n", -10);
/*    ft_printf("Imprimir un cero entero: %d. Done!\n", 0);
    ft_printf("Imprimir un entero positivo: %d. Done!\n", -10);
    ft_printf("Imprimir un hexadecimal: %x. Done!\n", -10);
    ft_printf("Imprimir un cero hexadecimal: %x. Done!\n", -10);
    ft_printf("Imprimir un puntero: %p. Done!\n", pointer_to_main);
*/
return (0);
}

void    ft_putchar(char c){
    write(1, &c, 1);
}