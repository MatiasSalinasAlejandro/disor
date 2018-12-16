module TranspuestaAgrupadaStore
    def initTranspuestaAgrupadaStore
        $textoTranspuestaA = ""
        $grupo = 0
    end

    def setGrupo(value)
        $grupo = value.to_i
    end

    def setTextoAgrupado(value)
        $textoTranspuestaA = value
    end
    
    def obtenerGrupo
        $grupo
    end

    def getTextoAgrupado
        $textoTranspuestaA
    end

    def transponerAgrupado()
        $caracteres = $textoTranspuestaA.split('')
        $textoAgrupado = ""
        $textoCifrado = ""
        $contador = 0
        if $grupo == 1
            return obtenerTranspuesta
        else
            for indice in(1..$caracteres.length)
                if $grupo != 0 and indice % $grupo == 0
                    $textoAgrupado = $textoAgrupado + $caracteres[indice-1]
                    $textoCifrado = $textoCifrado + $textoAgrupado.reverse
                    $textoAgrupado = ""
                    $contador = 0
                else
                    $textoAgrupado = $textoAgrupado +""+ $caracteres[indice-1].to_s
                    $contador = 1
                end
            end
            
            if $contador == 0
                return $textoCifrado
            else
                return $textoCifrado + $textoAgrupado
            end
        end
      end

end