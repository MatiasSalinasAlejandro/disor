module CifradoStore

  def init_cifrado_store
    @dezplazamiento = 0
    @textoCifrado = ""
  end

  def setTextoCifrado(value)
    @textoCifrado = value
  end

  def get_texto
    @textoCifrado
  end

  def setDezplazamieto(value)
    @dezplazamiento = value
  end

  def obtenerDezplazamiento
    @dezplazamiento
  end

end