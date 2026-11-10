
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    double t0;
    double dt;
    double H;
    double P;
    double C;
    double ta;
    double tw;
    double epsilon;
} Config;

static bool update_heater(bool ein, double t, const Config *cfg)
{
    if (t <= cfg->tw - cfg->epsilon)
        return true;
    if (t >= cfg->tw + cfg->epsilon)
        return false;
    return ein;
}

static double heat_loss(double t, const Config *cfg)
{
    return cfg->H * (t - cfg->ta);
}

static double step(double t, bool ein, const Config *cfg)
{
    const double power_in = ein ? cfg->P : 0.0;
    return t + (power_in - heat_loss(t, cfg)) * cfg->dt / cfg->C;
}

static void simulate(const Config *cfg, int minutes)
{
    bool ein = false;
    double t = cfg->t0;

    printf("Zeit [min];Temperatur [°C];Heizung [ein=1/aus=0]\n");

    for (int i = 0; i < minutes; i++)
    {
        ein = update_heater(ein, t, cfg);
        t = step(t, ein, cfg);
        printf("%d;%.4f;%d\n", i, t, ein ? 1 : 0);
    }
}

int main(void)
{
    const Config cfg = {
        .t0      = 21,
        .dt      = 60,
        .H       = 30,
        .P       = 2000,
        .C       = 4000000,
        .ta      = 12,
        .tw      = 21,
        .epsilon = 0.5,
    };

    simulate(&cfg, 24 * 60);
    return 0;
}