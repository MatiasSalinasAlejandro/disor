class TranspuestaAgrupado
    include Inesita::Component

  def espacios
    store.obtenerGrupo
  end

  def texto()
    store.transponerAgrupado()
  end

  def cambiarvalor(e)
    store.setGrupo(e.target.value)
    texto()
    render!
  end

  def render
      div class: 'col-md-12 offset-md-3 margenUp row' do
        text "Transpuesta Agrupado"
      end
      br
      div class: 'col-md-12 row' do
        label class: 'col-md-8' do
          text "Espacios: "
        end
        input.form_control type: "number",onclick: method(:cambiarvalor),class: 'col-md-4',value: espacios
      end
      br
      textarea class: 'col-md-12',onchange: method(:texto),value: texto do
      end
  end
end