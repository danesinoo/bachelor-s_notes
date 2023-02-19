use crate::matrici::CoefficienteMatrice;
type Num = f32;

impl CoefficienteMatrice for Num {
    fn new() -> Self {
        1.
    }
    fn nullo(&self) -> bool {
        *self == 0.
    }

    fn opposto(&self) -> Self {
        *self * -1.
    }
}

#[derive(Clone)]
pub struct MatriceReale {
    pub matrice: Vec<Num>,
    pub colonne: usize,
    pub righe: usize,
}

impl crate::matrici::Matrice<Num> for MatriceReale {
    fn new(righe: usize, colonne: usize) -> Self {
        Self {
            matrice: vec![0.; righe * colonne],
            colonne,
            righe,
        }
    }

    fn colonne(&self) -> usize {
        self.colonne
    }

    fn righe(&self) -> usize {
        self.righe
    }

    fn value(&self, index: usize) -> Num {
        self.matrice[index]
    }

    fn mut_value(&mut self, index: usize) -> &mut Num {
        &mut self.matrice[index]
    }

    fn len(&self) -> usize {
        self.matrice.len()
    }

    fn estrai_riga(&mut self, riga: usize) -> &mut [Num] {
        let from = riga * self.colonne;
        &mut self.matrice[from..from + self.colonne]
    }
}
