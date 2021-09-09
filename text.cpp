    // int width = image.cols;
    // int height = image.rows;
    // // cv::resize(image, image, cv::Size(0.5*width, 0.5*height), cv::INTER_CUBIC);

    // std::ifstream ix("/home/zw/rotate/x.txt");
    // std::ifstream iy("/home/zw/rotate/y.txt");
    // std::ifstream ifile("/home/zw/rotate/linePoint.txt");
    // cv::Mat out(1080, 1920, CV_8UC1);
    // double x, y;
    // while(1)
    // {
    //     ifile >> x;
    //     ifile >> y;
    //     cv::circle(out, cv::Point(x,y), 1, cv::Scalar(255,255,255), -1);
    //     std::cout<<x<<" "<<y<<std::endl;
    //     if(ifile.eof()) break;
    // }
    // // ix.close();
    // // iy.close();
    // ifile.close();


    /*
    std::ofstream ox("/home/zw/rotate/x.txt");
    std::ofstream oy("/home/zw/rotate/y.txt");
    double y,s;
    for(s = 0; s < 100000; s +=10)
    {
        splint(p, s, y);
        oy << y;
        oy << " ";
    }
    ox.close();
    oy.close();
    */

       // cv::Mat img = images[0];
    // Frame frame = frames[0];
    // std::vector<Event> events = frame.getEvents();
    // eventFilter(image, events);
    // parameter p;
    // getLineY(events, p);
    // std::ofstream ofile("/home/zw/rotate/line_para.txt");
    // if(ofile.is_open())
    // {
    //     for(int i = 0; i < p.size - 1; i++)
    //     {
    //         ofile << p.S[i];
    //         ofile << " ";
    //         ofile << p.A[i];
    //         ofile << " ";
    //         ofile << p.B[i];
    //         ofile << " ";
    //         ofile << p.C[i];
    //         ofile << " ";
    //         ofile << p.D[i];
    //         ofile << "\n";
    //         std::cout<<p.S[i]<<" "<<p.A[i]<<" "<<p.B[i]<<" "<<p.C[i]<<" "<<p.D[i]<<std::endl;
    //     }
    //     ofile << p.S[p.size - 1];
    // }
    // ofile.close();


        // cv::Mat image = images[0];
    // cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2,1));
    // cv::Mat element1 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1,2));
    // cv::Mat close_out = openOperate(image, element);
    // cv::Mat close_out1 = openOperate(close_out, element1);
    // cv::Mat thin_out(cv::Size(width, height), CV_8UC1);
    // getThin(close_out1, thin_out, 15);
    // valueTransform(image);
    // valueTransform(thin_out);
    
    // valueTransform(images[0]);
    // cv::imshow("i", images[0]);
    //cv::imshow("ii", thin_out);


        /* 
    std::vector<cv::Mat> images = readAllFrame("/home/zw/rotate/out.txt", 50.0);
    framePredication(images);
    std::vector<Frame> frames = readFrames("/home/zw/rotate/out.txt", 50.0);
    int width = images[0].cols;
    int height = images[0].rows;
    //frameFilter(images, frames);
    std::vector<Event> events = frames[0].getEvents();
    eventFilter(images[0], events);
    parameter px(events.size());
    parameter py(events.size());
    getLineXY(events, px, py);
    linePointWriter("/home/zw/rotate/linePoint.txt",px, py, width, height);
    */
   /*
    cv::Mat out(1080, 1920, CV_8UC1);
    lineDraw("/home/zw/rotate/linePoint.txt", out);
    cv::imshow("out", out);
    cv::waitKey(0);
    */
    /*
    std::ofstream ox("/home/zw/rotate/x.txt");
    std::ofstream oy("/home/zw/rotate/y.txt");
    if(ox.is_open() && oy.is_open())
    {
        double s, x, y;
        for(s = 0; s < 100000; s +=10)
        {
            splint(px,s,x);
            splint(py,s,y);
            if(x < 0 || y < 0 || x > width || y > height) 
                continue;
            ox << x;
            ox << " ";
            oy << y;
            oy << " ";
            if(ox.eof() || oy.eof()) break;
        }
    }
    ox.close();
    oy.close();

    std::ifstream ix("/home/zw/rotate/x.txt");
    std::ifstream iy("/home/zw/rotate/y.txt");
    cv::Mat out(1080, 1920, CV_8UC1);
    if(ix.is_open() && iy.is_open())
    {
        double x, y;
        while (1)
        {
            ix >> x;
            iy >> y;
            std::cout<<x<<" "<<y<<std::endl;
            cv::circle(out, cv::Point(x, y), 1, cv::Scalar(255,255,255), -1);
            if(ix.eof() || iy.eof()) break;
        }
    }
    ix.close();
    iy.close();
    cv::imshow("out", out);
    cv::waitKey(0);
*/
   /*
    linePointWriter("/home/zw/rotate/linePoint.txt",px,py,width,height);
    cv::Mat out(1080, 1920, CV_8UC1);
    lineDraw("/home/zw/rotate/linePoint.txt",out);
    */
    // double x,y,s;
    // for(s = 0; s < 100000; s +=10)
    // {   
    //     splint(px, s, x);
    //     splint(py, s, y);
    //     if(x < 0 || y < 0 || x > width || y > height) 
    //         continue;
    //     cv::circle(out, cv::Point(x,y), 1, cv::Scalar(255,255,255), -1);
        
    // }


    // valueTransform(image);
    // valueTransform(close_out1);
    // valueTransform(close_out2);
    // std::cout<<"Image:"<<pointCount(image)<<std::endl;
    // std::cout<<"close_out:"<<pointCount(close_out)<<std::endl;
    // std::cout<<"close_out1:"<<pointCount(close_out1)<<std::endl;
    // std::cout<<"thin_out:"<<pointCount(thin_out)<<std::endl;
    // // cv::morphologyEx(out, out, cv::MORPH_OPEN, element2);

    // std::vector<Event>::iterator itor = events.begin();
    // cv::Mat img(height, width, CV_8UC1);
    // while(itor != events.end())
    // {
    //     int row = (*itor).y;
    //     int col = (*itor).x;
    //     if(thin_out.at<uchar>(row,col) == 0)
    //     {
    //         itor = events.erase(itor);
    //     }
    //     else
    //     {
    //         img.at<uchar>(row, col) = 255;
    //         ++itor;
    //     }
    // }
    // // int p = image.at<uchar>(340,667);
    // // std::cout<<p<<std::endl;
    // // std::cout<<events[0].x<<" "<<events[0].y<<std::endl;
    // // cv::Mat result(height, width, CV_8UC1, img);
    // std::cout<<"result:"<<pointCount(img)<<std::endl;
    // cv::imshow("IMAGE", image);
    // cv::imshow("close", close_out);
    // cv::imshow("close1", close_out1);
    // cv::imshow("close2", close_out2);
    // cv::imshow("thin", thin_out);
    // cv::imshow("img", img);
    // cv::waitKey(0);