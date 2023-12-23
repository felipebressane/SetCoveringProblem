#/mestrado/projetos/scp/bin/scp	

export DIR_BIN=/mestrado/projetos/scp/bin
export INPUT_DATA_DIR=/mestrado/projetos/scp/data
export REPORT_DIR=/mestrado/projetos/scp/rpt

export PRINTSCREEN=1

# Primeira Execução
#export FACTOR_EXECUTIONS=10
#export DEADLINE=1

# Segunda Execução
#export FACTOR_EXECUTIONS=10
#export DEADLINE=4

# Terceira Execução
export FACTOR_EXECUTIONS=11
export DEADLINE=6

# Teste
#export FACTOR_EXECUTIONS=10
#export DEADLINE=2


$DIR_BIN/scp $1 $2

exit 0
