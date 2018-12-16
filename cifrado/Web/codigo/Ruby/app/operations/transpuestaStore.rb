module TrnaspuestaStore


    def init_transpuesta_store
        $textoTranspuesta = ""
    end

    def obtenerTranspuesta
        $textoTranspuesta
    end

    def setTranspuesta(value)
        $textoTranspuesta = value.reverse
    end
end