module Cifrador
    def init_cifrador(alfabeto)
            @alfabeto = alfabeto
    end

    def cifrarCaracter(recorrido,caracter)
        posicion = @alfabeto.obtenerPosicion(caracter)
        if posicion > 0
            return @alfabeto.obtenerCaracter(posicion+recorrido)
        else
            return caracter
        end
    end

    def cifrarTexto(recorrido,texto)
        textoCifrado = ""
        texto.chars.each{
            |caracter| textoCifrado = textoCifrado + cifrarCaracter(recorrido,caracter)
        }
        return textoCifrado
    end
end