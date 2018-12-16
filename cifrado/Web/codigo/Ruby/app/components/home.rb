class Home
  include Inesita::Component

  def render
    div.jumbotron.bg_light do
      div do
        component Texto
      end
      br

      div class: 'col-md-12 row' do
        div class: 'col-md-3 border border-secondary' do
          component CifradoCesar
        end 

        div class: 'col-md-3 offset-md-1 border border-secondary' do
          component Transpuesta
        end

        div class: 'col-md-3 offset-md-1 border border-secondary' do
          component TranspuestaAgrupado
        end
      end  
    
    end
  end
end