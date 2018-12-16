class Transpuesta
    include Inesita::Component

    def getTranspuesta()
        store.obtenerTranspuesta
    end

    def render
        div class: 'col-md-12 offset-md-3 margenUp row' do
          text "Transpuesta"
        end
        br
        textarea class: 'col-md-12',value: getTranspuesta do
        end
    end

end