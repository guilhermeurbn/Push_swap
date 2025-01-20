/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:19:18 by guisanto          #+#    #+#             */
/*   Updated: 2025/01/20 13:37:32 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//radix Sort
void count_sort(int *stack, int n, int exp)
{
    int *output = malloc(n * sizeof(*stack));//vai armazenar meus resultados
    int count[10] = {0}; //preenchendo um array de 10 digitos de 0
    int i = 0;
    
    //vamo contar quantas ocorrencias de numeros ocorreram
    while(i < n)
    {
        count[(stack[i] / exp) % 10]++;
        i++;
    }
        
    //atulizando meu Array_count para conter as posições finais
    i = 1;
    while(i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }
        
    //construindo meu array de saida
    i = n - 1;
    while(i >= 0)
    {
        output[count[(stack[i] / exp) % 10] - 1] = stack[i];
        count[(stack[i] / exp) % 10]--;
        i--;
    }
    
    //copiando tudo de volta para a stack em ordem do maior para o menor
    i = 0;
    while(i < n)
    {
        stack[i] = output[i];
        i++;
    }
    free(output);
}
