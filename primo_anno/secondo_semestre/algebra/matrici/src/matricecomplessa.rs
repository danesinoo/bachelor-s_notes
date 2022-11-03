use crate::matrici::{CoefficienteMatrice, Matrice};
use crate::complesso::*;
use std::fmt;

#[derive(Clone)]
pub struct MatriceComplessa {
    pub matrice: Vec<Complesso<Gen>>,
    pub righe: usize,
    pub colonne: usize
}

impl std::fmt::Display for MatriceComplessa {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let mut result= format!("");
        for i in 0..self.righe {
            for j in 0..self.colonne {
                result= format!("{}{}   ", result, self.matrice[i * self.colonne + j]);
            }
            result += "\n";
        }
        write!(f, "{}", result)
    }
}

impl Matrice<Complesso<Gen>> for MatriceComplessa {
    fn new(righe: usize, colonne: usize) -> Self {
        MatriceComplessa { 
            matrice: vec![Complesso::<Gen>::new(); righe * colonne], 
            righe, 
            colonne
        }
    }

    fn colonne(&self) -> usize {
        self.colonne
    }

    fn righe(&self) -> usize {
        self.righe
    }

    fn value(&self, index: usize) -> Complesso<Gen> {
        self.matrice[index]
    }

    fn mut_value(&mut self, index: usize) -> &mut Complesso<Gen> {
        &mut self.matrice[index]
    }

    fn len(&self) -> usize {
        self.matrice.len()
    }

    fn estrai_riga(&mut self, riga: usize) -> &mut [Complesso<Gen>] {
        let from = riga * self.colonne;
        &mut self.matrice[from..from+self.colonne]

    }
}

/*
    let matrice: Vec<Complesso<Gen>> = vec![
        Complesso{re: 9., im: 0.},
        Complesso{re: 6., im: 1.},
        Complesso{re: 1., im: 0.},

        Complesso{re: 3., im: 0.},
        Complesso{re: 18., im: 0.},
        Complesso{re: 1., im: 0.},

        Complesso{re: 1., im: 0.},
        Complesso{re: 2., im: 1.},
        Complesso{re: 1., im: 0.}
    ];

    let mut mat_comp= MatriceComplessa{
        matrice,
        righe: 3,
        colonne: 3
    };

    mat_comp = mat_comp.mul(&mat_comp).unwrap();

    print!("{}\n", mat_comp.table());
    */
