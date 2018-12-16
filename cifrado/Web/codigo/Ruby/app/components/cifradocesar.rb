class CifradoCesar
    include Inesita::Component

    def texto()
      store.cifrarTexto(store.obtenerDezplazamiento.to_i,store.get_texto)
    end

    def cambiarvalor(e)
      store.setDezplazamieto(e.target.value);
      texto()
      render!
    end  
    
    def desplazamiento
      store.obtenerDezplazamiento
    end

    def render
      div class: 'col-md-12 offset-md-3 margenUp row' do
        text "Cifrado Cesar"
      end
      br
      div class: 'col-md-12 row' do
        label class: 'col-md-8' do
          text "Desplazamiento: "
        end
        input.form_control type: "number",onclick: method(:cambiarvalor), class: 'col-md-4',value: desplazamiento
      end
      br
      textarea class: 'col-md-12',onchange: method(:texto),value: texto do
      end
    end

end