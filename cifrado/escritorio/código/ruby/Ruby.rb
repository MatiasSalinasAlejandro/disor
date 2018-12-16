class Inverso
    @Texto
    def initialize(entrada)
        @Texto=invertir(entrada)
    end

    def invertir(entrada)
        string_reves=""
        i=0
        while i<entrada.length
            string_reves=entrada[i]+string_reves
            i+=1
        end
        return string_reves
    end

    def getMensaje
        return @Texto
    end
    
end


class Cesar
    @Texto
    def initialize(entrada,desplazamiento)
        @Texto=cifrar(entrada,desplazamiento)
    end 

    def cifrar(texto,semilla)
        salida=""
        texto.length.times do |index| 
            if /[a-z]/.match(texto[index])
              letter = texto[index].ord + semilla
              if letter > "z".ord
                salida.concat((letter - 26).chr)
              else
                salida.concat(letter.chr)
              end
            elsif /[A-Z]/.match(texto[index])
              letter = texto[index].ord + semilla
              if letter > "Z".ord
                salida.concat((letter - 26).chr)
              else
                salida.concat(letter.chr)
              end
            else
                salida.concat(texto[index])
            end
          end
          return salida
    end


    def getMensaje()
        @Texto
    end
end


class InversoGrupal
    @Texto

    def initialize(entrada,semilla)
        @Texto=invertir(entrada,semilla)
    end

    def invertir(entrada,semilla)
        nuevo=entrada.delete(" ")
        sobran = nuevo.length % semilla
        salida=nuevo.scan(/.{#{semilla}}/).map {|c| Inverso.new(c).getMensaje.concat(" ")}.join
        salida.concat(nuevo.chars.last(sobran).join)
    end

    def getMensaje
        return @Texto
    end
end


entrada="Hola me llamo juan"


inversoGrupal=InversoGrupal.new(entrada,3)
puts inversoGrupal.getMensaje
