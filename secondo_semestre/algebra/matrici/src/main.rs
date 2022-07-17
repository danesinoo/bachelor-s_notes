mod matricecomplessa;
pub mod matrici;
mod complesso;
use complesso::{Complesso, Gen};
use matricecomplessa::MatriceComplessa;
use matrici::Matrice; 

fn main() {
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

    let mat_comp= MatriceComplessa{
        matrice,
        righe: 3,
        colonne: 3
    };

    print!("{}\n", mat_comp);
    print!("\n{}\n", mat_comp.mol_mat(&mat_comp).unwrap());
}
