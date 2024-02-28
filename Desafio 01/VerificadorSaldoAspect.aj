// VerificadorSaldoAspect.aj
public aspect VerificadorSaldoAspect {
    pointcut sacarOperation(double valor):
        execution(* ContaBancaria.sacar(double)) && args(valor);

    before(double valor): sacarOperation(valor) {
        System.out.println("Verificando saldo antes do saque...");
    }

    after(double valor): sacarOperation(valor) {
        System.out.println("Verificação de saldo concluída.");
    }
}
