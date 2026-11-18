#include<string>
#include<cmath>

#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>

int main(int argc, char* argv[]){
    std::string file_path = "../dados/maps.png";

    //Abrir uma imagem
    cv::Mat imagem_lida = cv::imread(file_path, cv::IMREAD_COLOR); //IMREAD_GRAYSCALE deixa img cinza

    //Exibir a imagem
    cv::imshow("Janela da Imagem Lida", imagem_lida);
    int key = cv::waitKey(0);

    //Gerar uma imagem do zero
    int num_linhas = 400;
    int num_cols = 500;
    cv::Mat img_synth(num_linhas, num_cols, CV_8UC1, cv::Scalar(0));
    for(int i = 0; i < img_synth.rows; ++i){
        for(int j = 0; j < img_synth.cols; ++j){
            float prop_linha = static_cast<float>(i) / static_cast<float>(img_synth.rows);
            float prop_col = static_cast<float>(j) / static_cast<float>(img_synth.cols);
            unsigned char p = static_cast<unsigned char>(255 * round(prop_linha * 0.5 + prop_col * 0.5));
            img_synth.at<unsigned char>(i,j) = p;
        }
    }

    cv::imshow("Janela da Imagem Sintetica", img_synth);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}