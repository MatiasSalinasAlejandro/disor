class Store
  include Inesita::Injection
  include CifradoStore
  include TextoStore
  include Cifrador
  include TrnaspuestaStore
  include TranspuestaAgrupadaStore

  #attr_accessor :counter
  

  def init
    init_cifrado_store
    init_texto_store
    init_transpuesta_store
    initTranspuestaAgrupadaStore
    alfabeto = Alfabeto.new()
    init_cifrador(alfabeto)
    @counter = 0
  end
  
end