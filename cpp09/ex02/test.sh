#!/bin/bash

# Gerar 300 números aleatórios entre 1 e 1000
numbers=$(shuf -i 1-100000 -n 8000 | tr '\n' ' ')

# Executar o programa com os números gerados
./PmergeMe "$numbers"