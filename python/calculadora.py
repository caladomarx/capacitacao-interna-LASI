
# MULTICALCULADORA

# Variável que indica qual calculadora está selecionada
calculadora_atual = "basica"

# LOOP PRINCIPAL

while True:

    # MENU SUPERIOR

    print("=====================================")
    print(" CALCULADORA DE TROCO")
    print(" CALCULADORA BÁSICA")
    print(" CALCULADORA DE RESISTÊNCIA")
    print("=====================================")

    print(f"\nCalculadora selecionada: {calculadora_atual}")

    # ESCOLHA DA CALCULADORA

    print("\n1 - Troco")
    print("2 - Básica")
    print("3 - Resistência")
    print("0 - Sair")

    opcao = input("\nEscolha: ")

    # ENCERRAR PROGRAMA

    if opcao == "0":
        break

    # CALCULADORA DE TROCO

    elif opcao == "1":

        calculadora_atual = "troco"

        print("\n=== CALCULADORA DE TROCO ===")

        # pedir valor da compra
        # calcular troco
        # mostrar troco

        input("\nPressione ENTER...")

    # CALCULADORA BÁSICA

    elif opcao == "2":

        calculadora_atual = "basica"

        print("\n=== CALCULADORA BÁSICA ===")

        # pedir expressão
        # calcular resultado
        # tratamento de erros

        input("\nPressione ENTER...")

    # CALCULADORA DE RESISTÊNCIA

    elif opcao == "3":

        calculadora_atual = "resistencia"

        print("\n=== CALCULADORA DE RESISTÊNCIA ===")

        # escolher série ou paralelo
        # informar resistores
        # calcular resistência equivalente

        input("\nPressione ENTER...")

    else:

        print("\nOpção inválida.")
        input("\nPressione ENTER...")