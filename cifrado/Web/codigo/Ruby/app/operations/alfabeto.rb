class Alfabeto
    $alfabeto = []

    def initialize()
        (0..254).each do |x|
            if( x.chr(Encoding::UTF_8).gsub(/[^[:print:]]/i, '') != "" )
              $alfabeto.push(x.chr(Encoding::UTF_8) ) 
            end
        end
    end

    def obtenerCaracter(posicion)
        if posicion > $alfabeto.length
            return $alfabeto[(posicion-$alfabeto.length)-1]
        elsif posicion < 0
            return $alfabeto[(posicion+$alfabeto.length)+1]
        else
            return $alfabeto[posicion]
        end
    end 

    def obtenerPosicion(caracter)
        if $alfabeto.include?(caracter)
            return $alfabeto.index(caracter)
        else
            return -1
        end
    end

    def obtenerTamanio()
        return $alfabeto.length
    end 

    def getAlfabeto()
        return $alfabeto.length
    end
end