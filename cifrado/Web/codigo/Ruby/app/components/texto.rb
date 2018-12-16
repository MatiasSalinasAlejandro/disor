class Texto
    include Inesita::Component

    def cambiarTexto(e)
        store.setTextoCifrado(e.target.value)
        store.setTranspuesta(e.target.value)
        store.setTextoAgrupado(e.target.value)
        render!
    end
    
    def render
        div do
            div class: 'col-md-12 row' do
                h4 class: 'col-md-2' do
                    text "Texto"
                end
                input.form_control type: "text",onkeyup: method(:cambiarTexto),class: 'col-md-10'
            end
        end
    end
end