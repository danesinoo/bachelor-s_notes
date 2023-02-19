use std::fmt::Display;
use std::ops::{AddAssign, Mul, SubAssign};

use crate::matrici::CoefficienteMatrice;
pub(crate) type Gen = f32;

pub struct Complesso<T>
where
    T: Display + AddAssign + SubAssign + Mul + Clone + Copy,
{
    pub re: T,
    pub im: T,
}

impl CoefficienteMatrice for Complesso<Gen> {
    fn new() -> Self {
        Complesso { re: 1., im: 0. }
    }

    fn nullo(&self) -> bool {
        self.re == 0. && self.im == 0.
    }

    fn opposto(&self) -> Self {
        Complesso {
            re: self.re * -1.,
            im: self.im * -1.,
        }
    }
}

impl Complesso<Gen> {
    pub fn modulo(&self) -> Gen {
        self.re * self.re + self.im * self.im
    }
}

mod impl_for_complesso {
    use crate::complesso::Complesso;
    use std::fmt::Display;
    use std::ops::{Add, Div, Mul, Sub};
    type Gen = super::Gen;
    impl Add for Complesso<Gen> {
        type Output = Self;
        fn add(mut self, rhs: Self) -> Self::Output {
            self.re += rhs.re;
            self.im += rhs.im;
            self
        }
    }

    impl Sub for Complesso<Gen> {
        type Output = Self;
        fn sub(mut self, rhs: Self) -> Self::Output {
            self.re -= rhs.re;
            self.im -= rhs.im;
            self
        }
    }

    impl Mul for Complesso<Gen> {
        type Output = Self;
        fn mul(mut self, rhs: Self) -> Self::Output {
            let re = self.re * rhs.re - self.im * rhs.im;
            self.im = self.im * rhs.re + self.re * rhs.im;
            self.re = re;
            self
        }
    }

    impl Div for Complesso<Gen> {
        type Output = Self;
        fn div(mut self, rhs: Self) -> Self::Output {
            let re = (self.re * rhs.re + self.im * rhs.im) / rhs.modulo();
            self.im = (self.im * rhs.re - self.re * rhs.im) / rhs.modulo();
            self.re = re;
            self
        }
    }

    impl Display for Complesso<Gen> {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            if self.re == 0. {
                if self.im == 0. {
                    write!(f, "0")
                } else {
                    write!(f, "{}i", self.im)
                }
            } else if self.im == 0. {
                write!(f, "{}", self.re)
            } else if self.im > 0. {
                write!(f, "{}+{}i", self.re, self.im)
            } else {
                write!(f, "{}{}i", self.re, self.im)
            }
        }
    }

    impl Clone for Complesso<Gen> {
        fn clone(&self) -> Self {
            Self {
                re: self.re.clone(),
                im: self.im.clone(),
            }
        }
    }

    impl Copy for Complesso<Gen> {}
}
