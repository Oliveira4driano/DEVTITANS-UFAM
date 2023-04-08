#!/bin/bash

echo -n "Digite um número: "
read NUMBER

if [ $NUMBER -gt 0 ]; then
    echo "O número $NUMBER é maior que zero!"
elif [ $NUMBER -eq 0 ]; then
    echo "O número $NUMBER é zero!"
else
    echo "O número $NUMBER é menor que zero!"
fi